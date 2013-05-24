<?php

class AACRBiblioMigrate extends DynamicMigration {
  public function __construct($group = NULL) {
    parent::__construct();
    $this->machineName = 'AACRBiblioMigrate';
    $this->description = 'Imports total migrate files from the aacr system';
    $this->dependencies[] = 'AACRBiblioKeywords';
    $this->dependencies[] = 'AACRBiblioContributers';
    
    $extra_fields = array();
    
    $sub_query = Database::getConnection('default', 'crcstl')
        ->select('biblio_keyword', 'bk');
    $sub_query->fields('bk', array('nid'));
    $sub_query->leftJoin('biblio_keyword_data', 'bkd', 'bk.kid = bkd.kid');
    $sub_query->condition('bkd.word', 'AACR', '=');
    
    $source_query = Database::getConnection('default', 'crcstl')
        ->select('node', 'n');
    $source_query->leftJoin('biblio', 'b', 'n.vid = b.vid');
    $source_query->leftJoin('users', 'u', 'n.uid = u.uid');
    $source_query->condition('n.type', 'biblio', '=');
    $source_query->condition('n.nid', $sub_query, 'IN');
    $source_query->fields('n');
    $source_query->fields('b');
    $source_query->fields('u', array('mail'));
    $source_query->orderBy('n.nid');
    
    $extra_fields['biblio_keywords'] = t('Keywords from old installation');
    $extra_fields['biblio_contributors'] = t('Contributers from old installation');
    $extra_fields['uid'] = t('Calculated uid');
    
    $this->destination = new MigrateDestinationNode('biblio');
    $this->source = new MigrateSourceSQL($source_query, $extra_fields, $source_query->countQuery(), array('map_joinable' => false));
    $this->map = new MigrateSQLMap($this->machineName,
        MigrateDestinationNode::getKeySchema(),
        MigrateDestinationNode::getKeySchema());
    
    $this->addSimpleMappings(array('title', 'status', 'promote', 'created', 'changed',
      'comment', 'sticky', 'tnid', 'translate', 'biblio_type', 'biblio_number',
      'biblio_other_number', 'biblio_secondary_title', 'biblio_tertiary_title',
      'biblio_edition', 'biblio_publisher', 'biblio_place_published', 'biblio_year',
      'biblio_volume', 'biblio_pages', 'biblio_date', 'biblio_isbn', 'biblio_full_text',
      'biblio_url', 'biblio_issue', 'biblio_type_of_work', 'biblio_accession_number',
      'biblio_call_number', 'biblio_notes', 'biblio_research_notes', 'biblio_number_of_volumes',
      'biblio_short_title', 'biblio_alternate_title', 'biblio_original_publication',
      'biblio_reprint_edition', 'biblio_translated_title', 'biblio_section',
      'biblio_citekey', 'biblio_coins', 'biblio_doi', 'biblio_issn', 'biblio_auth_address',
      'biblio_remote_db_name', 'biblio_remote_db_provider', 'biblio_label', 'biblio_access_date',
      'biblio_md5', 'biblio_refereed', 'biblio_custom1', 'biblio_custom2', 'biblio_custom3',
      'biblio_custom4', 'biblio_custom5', 'biblio_custom6', 'biblio_custom7'));
    
    
    $this->addFieldMapping('biblio_keywords', 'biblio_keywords');
    
    $this->addFieldMapping('body', 'biblio_abst_e');
    $this->addFieldMapping('body:summary', 'biblio_abst_f');
    
    $this->addFieldMapping('uid', 'uid');
    //$this->addFieldMapping('og_group_ref')->defaultValue('408');
    

    
    $this->addFieldMapping('log')->defaultValue('Importing from AACR/CRCSTL Database');
    $this->addFieldMapping('language')->defaultValue('und');
    $this->addFieldMapping('revision_uid')->defaultValue(1);
    $this->addFieldMapping('body:format')->defaultValue('filtered_html');
    $this->addFieldMapping('body:language')->defaultValue('und');
    
    $this->addUnmigratedSources(array('type', 'language', 'moderate', 'vid', 'biblio_lang',
      ));
    $this->addUnmigratedDestinations(array('path', 'biblio_sort_title', 'biblio_formats', 'type'));
  }
  
  public function prepareRow($row) {
    parent::prepareRow($row);
    
    $row->biblio_keyword = array();
    
    // Get all the keywords
    $keyword_query = Database::getConnection('default', 'crcstl')
        ->select('biblio_keyword', 'bk');
    $keyword_query->leftJoin('biblio_keyword_data', 'bkd', 'bkd.kid = bk.kid');
    $keyword_query->fields('bkd', array('word'));
    $keyword_query->condition('nid', $row->nid, '=');
    $keyword_query->condition('bkd.word', 'AACR-pub', '!='); // Asked to not migrate  
    $keyword_results = $keyword_query->execute();
    while ($keyword = $keyword_results->fetchAssoc()) {
      $row->biblio_keywords[] = $keyword['word'];
    }
    
    if (isset($row->mail) && !empty($row->mail)) {
      $uid_from_email = db_query('SELECT uid FROM users WHERE mail = :mail', array(':mail' => $row->mail))->fetchField();
      if ($uid_from_email) {
        $row->uid = $uid_from_email;
        $this->queueMessage(t('Able to get UID @uid from email address @mail', array('@uid' => $uid_from_email, '@mail' => $row->mail)), Migration::MESSAGE_INFORMATIONAL);
      }
      else {
        $this->queueMessage(t('Unable to get UID from email address @mail', array('@mail' => $row->mail)), Migration::MESSAGE_INFORMATIONAL);
        $row->uid = 1;
      }
    }
    else {
      $row->uid = 1;
    }
    
    unset($row->type);
    
  }
}
