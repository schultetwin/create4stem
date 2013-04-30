<?php

class BiblioDestinationHandler extends MigrateDestinationHandler {
  public function __construct() {
     $this->registerTypes(array('node'));
  }
  
  public function fields($entity_type, $bundle) {
    $fields = array();
    if ($entity_type != 'node' || $bundle != 'biblio') {
      return $fields;
    }
    
    $fields['biblio_type'] = t('Biblio: Biblio Type (int)');
    $fields['biblio_number'] = t('Biblio: Biblio Number (varchar)');
    $fields['biblio_other_number'] = t('Biblio: Biblio Other Number (varchar)');
    $fields['biblio_sort_title'] = t('Biblio: Sort Title, normalized version of the title');
    $fields['biblio_secondary_title'] = t('Biblio: Secondary Title');
    $fields['biblio_tertiary_title'] = t('Biblio: Tertiary Title');
    $fields['biblio_edition'] = t('Biblio: Edition');
    $fields['biblio_publisher'] = t('Biblio: Publisher');
    $fields['biblio_place_published'] = t('Biblio: Place Published');
    $fields['biblio_year'] = t('Biblio: Year');
    $fields['biblio_volume'] = t('Biblio: Volume');
    $fields['biblio_pages'] = t('Biblio: Pages');
    $fields['biblio_date'] = t('Biblio: Date');
    $fields['biblio_isbn'] = t('Biblio: ISBN');
    $fields['biblio_full_text'] = t('Biblio: Full Text');
    $fields['biblio_url'] = t('Biblio: URL');
    $fields['biblio_issue'] = t('Biblio: Issue');
    $fields['biblio_type_of_work'] = t('Biblio: Type of Work');
    $fields['biblio_accession_number'] = t('Biblio: Accession number');
    $fields['biblio_call_number'] = t('Biblio: Call Number');
    $fields['biblio_notes'] = t('Biblio: Notes');
    $fields['biblio_research_notes'] = t('Biblio: Research Notes');
    $fields['biblio_number_of_volumes'] = t('Biblio: Number of volumes');
    $fields['biblio_short_title'] = t('Biblio: Short Title');
    $fields['biblio_alternate_title'] = t('Biblio: Alternate Title');
    $fields['biblio_original_publication'] = t('Biblio: Original Publication');
    $fields['biblio_reprint_edition'] = t('Biblio: Reprint Edition');
    $fields['biblio_translated_title'] = t('Biblio: Translated title');
    $fields['biblio_section'] = t('Biblio: Section');
    $fields['biblio_citekey'] = t('Biblio: CiteKey');
    $fields['biblio_coins'] = t('Biblio: Coins');
    $fields['biblio_doi'] = t('Biblio: DOI');
    $fields['biblio_issn'] = t('Biblio: ISSN');
    $fields['biblio_auth_address'] = t('Biblio: Auth Address');
    $fields['biblio_remote_db_name'] = t('Biblio: Remote DB Name');
    $fields['biblio_remote_db_provider'] = t('Biblio: Remote DB Provider');
    $fields['biblio_label'] = t('Biblio: Label');
    $fields['biblio_access_date'] = t('Biblio: Access Date');
    $fields['biblio_refereed'] = t('Biblio Refereed');
    $fields['biblio_md5'] = t('Biblio: MD5');
    $fields['biblio_formats'] = t('Biblio: Formats');
    $fields['biblio_custom1'] = t('Biblio: Custom 1');
    $fields['biblio_custom2'] = t('Biblio: Custom 2');
    $fields['biblio_custom3'] = t('Biblio: Custom 3');
    $fields['biblio_custom4'] = t('Biblio: Custom 4');
    $fields['biblio_custom5'] = t('Biblio: Custom 5');
    $fields['biblio_custom6'] = t('Biblio: Custom 6');
    $fields['biblio_custom7'] = t('Biblio: Custom 7');
    $fields['biblio_keywords'] = t('Biblio Keywords (can be array)');
    $fields['biblio_contributors'] = t('Biblio Contributers');
    
    return $fields;
  }
}