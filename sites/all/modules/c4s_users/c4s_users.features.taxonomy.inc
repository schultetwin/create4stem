<?php
/**
 * @file
 * c4s_users.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function c4s_users_taxonomy_default_vocabularies() {
  return array(
    'institute_position' => array(
      'name' => 'Institute Position',
      'machine_name' => 'institute_position',
      'description' => 'Individual user\'s relationship to the Institute (for search/display)',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
