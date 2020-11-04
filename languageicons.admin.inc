<?php
/**
 * @file
 * Admin page callbacks for the Language Icons module.
 */

/**
 * Form builder; configure Language Icons.
 *
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function languageicons_admin_settings() {
  $config = config('languageicons.settings');
  backdrop_set_title('Language icons configuration');
  $form['#config'] = 'languageicons.settings';
  $form['show'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add language icons'),
    '#description' => t('Link types to add language icons.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['show']['languageicons_show_node'] = array(
    '#type' => 'checkbox',
    '#title' => t('Node links'),
    '#default_value' => $config->get('languageicons_show_node'),
    '#disabled' => FALSE,
  );
  $form['show']['languageicons_show_block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Language switcher block'),
    '#default_value' => $config->get('languageicons_show_block'),
    '#disabled' => FALSE,
  );

  $form['languageicons_placement'] = array(
    '#type' => 'radios',
    '#title' => t('Icon placement'),
    '#options' => array(
      'before' => t('Before link'),
      'after' => t('After link'),
      'replace' => t('Replace link'),
    ),
    '#default_value' => $config->get('languageicons_placement'),
    '#description' => t('Where to display the icon, relative to the link title.'),
  );
  $form['languageicons_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Icons file path'),
    '#default_value' => $config->get('languageicons_path'),
    '#size' => 70,
    '#maxlength' => 180,
    '#description' => t('Path for language icons, relative to Backdrop installation. "*" is a placeholder for language code.'),
  );
  $form['languageicons_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Image size'),
    '#default_value' => $config->get('languageicons_size'),
    '#size' => 7,
    '#maxlength' => 7,
    '#description' => t('Image size for language icons, in the form "width x height".'),
  );

  return system_settings_form($form);
}
