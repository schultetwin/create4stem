<?php
/**
 * @file
 * c4s_stories.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function c4s_stories_taxonomy_default_vocabularies() {
  return array(
    'story_type' => array(
      'name' => 'Story Type',
      'machine_name' => 'story_type',
      'description' => 'Tags to direct stories to their appropriate location',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '-9',
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
