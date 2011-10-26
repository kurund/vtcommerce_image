<?php

function vt_lavalamp_admin_settings($form, &$form_state) {
  $form['vt_lavalamp_root'] = array(
  '#type' => 'fieldset',
  '#weight' => -19,
  '#title' => t('Basic settings'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  );
	$data = unserialize(variable_get('vt_lavalamp', ''));
  $options = menu_get_menus(TRUE);
  $form['vt_lavalamp_root']['vt_lavalamp_root_type'] = array(
  '#type' => 'select',
  '#title' => t('Please select menu source'),
  '#options' => $options,
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_root_type', 'navigation:0'),
  );
  
  $options_theme = vt_lavalamp_read_dir('vt_lavalamp');
  $form['vt_lavalamp_root']['vt_lavalamp_theme'] = array(
  '#type' => 'select',
  '#title' => t('Please select theme style'),
  '#options' => $options_theme,
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_theme', 'blue'),
  );
  if (module_exists('i18n_menu')) {
  $form['vt_lavalamp_root']['vt_lavalamp_urlsort'] = array(
  '#type' => 'select',
  '#title' => t('Sort menu per language url?'),
  '#description' => t('Example if your url is http://somehost.com/en then by selecting true only menu marked with en (english) language will be shown'),
  '#options' => array('true' => 'True', 'false' => 'False'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_urlsort', 'true'),
  ); 
  $form['vt_lavalamp_root']['vt_lavalamp_undurl'] = array(
  '#type' => 'select',
  '#title' => t('Show undefined language menu?'),
  '#description' => t('Example if your url is http://somehost.com/en then by selecting true menu marked with und (undefined) language will be shown'),
  '#options' => array('true' => 'True', 'false' => 'False'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_undurl', 'true'),
  );  
  }
  $form['vt_lavalamp_plugin_root'] = array(
  '#type' => 'fieldset',
  '#weight' => -17,
  '#title' => t('jQuery plugin settings'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  );
  $options_easing = array("jswing" => 'jswing' , "def" => 'def' , "easeInQuad" => 'easeInQuad' , "easeOutQuad" => 'easeOutQuad' , "easeInOutQuad" => 'easeInOutQuad' , "easeInCubic" => 'easeInCubic' , "easeOutCubic" => 'easeOutCubic', "easeInOutCubic" => 'easeInOutCubic' , "easeInQuart" => 'easeInQuart' , "easeOutQuart" => 'easeOutQuart' , "easeInOutQuart" => 'easeInOutQuart' , "easeInQuint" => 'easeInQuint' , "easeOutQuint" => 'easeOutQuint' , "easeInOutQuint" => 'easeInOutQuint' , "easeInSine" => 'easeInSine' , "easeOutSine" => 'easeOutSine' , "easeInOutSine" => 'easeInOutSine', "easeInExpo" => 'easeInExpo' , "easeOutExpo" => 'easeOutExpo' , "easeInOutExpo" => 'easeInOutExpo' , "easeInCirc" => 'easeInCirc', "easeOutCirc" => 'easeOutCirc' , "easeInOutCirc" => 'easeInOutCirc' , "easeInElastic" => 'easeInElastic' , "easeOutElastic" => 'easeOutElastic' , "easeInOutElastic" => 'easeInOutElastic' , "easeInBack" => 'easeInBack' , "easeOutBack" => 'easeOutBack' , "easeInOutBack" => 'easeInOutBack' , "easeInBounce" => 'easeInBounce' , "easeOutBounce" => 'easeOutBounce' , "easeInOutBounce" => 'easeInOutBounce');
  
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_target'] = array(
  '#type' => 'textfield',
  '#title' => t('The lavalamp target html tag, if unsure leave it to default value : li'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_target', 'li'),
  '#description' => t('defines the elements to target inside the container passed to lavaLamp, valid value are html tags such as p, div, li, a, span'),
  );
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_container'] = array(
  '#type' => 'textfield',
  '#title' => t('DOM element to create for the hover element. If container is empty, LavaLamp will assume it is the same as the target option, if unsure leave it to default value : li'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_container', 'li'),
  '#description' => t('Valid value are html tags such as p, div, li, a, span'),
  );
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_easing'] = array(
  '#type' => 'select',
  '#title' => t('Select jQuery easing style'),
  '#options' => $options_easing,
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_easing', 'jswing'),
  );
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_speed'] = array(
  '#type' => 'textfield',
  '#title' => t('Set the animation speed'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_speed', '1000'),
  );
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_start_item'] = array(
  '#type' => 'textfield',
  '#title' => t('Set the start item'),
  '#description' => t('Specifies the number target element as default, starting with 0 for the first element Used to manually set the default lavaLamp highlight on load.'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_start_item', 'no'),
  );
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_auto_return'] = array(
  '#type' => 'select',
  '#options' => array('true' => 'True', 'false' => 'False'),
  '#title' => t('Set the auto return feature'),
  '#description' => t('Defines whether the backLava hover should return to the last selectedLava element upon mouseleave.'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_auto_return', 'true'),
  );
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_return_delay'] = array(
  '#type' => 'textfield',
  '#title' => t('Set auto return delay time'),
  '#description' => t('How many milliseconds to wait before returning the backLava element to the last selected element. Only works if autoReturn is set to true (default setting)'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_return_delay', '0'),
  );
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_set_on_click'] = array(
  '#type' => 'select',
  '#title' => t('Set the on click feature'),
  '#options' => array('true' => 'True', 'false' => 'False'),
  '#description' => t('Defines whether a clicked element should receive the selectLava class and become the most recently selected element'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_set_on_click', 'true'),
  );
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_home_top'] = array(
  '#type' => 'textfield',
  '#title' => t('Set the home top position'),
  '#description' => t('Allows you to define an independent \'home\' element where the backLava defaults to or can be sent to. This can be used to define a unique starting and/or resting place for the backLava upon leaving the parent element'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_home_top', '0'),
  );
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_home_left'] = array(
  '#type' => 'textfield',
  '#title' => t('Set the home left position'),
  '#description' => t('Allows you to define an independent \'home\' element where the backLava defaults to or can be sent to. This can be used to define a unique starting and/or resting place for the backLava upon leaving the parent element.'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_home_left', '0'),
  );
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_home_width'] = array(
  '#type' => 'textfield',
  '#title' => t('Set the home width'),
  '#description' => t('Allows you to define an independent \'home\' element where the backLava defaults to or can be sent to. This can be used to define a unique starting and/or resting place for the backLava upon leaving the parent element.'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_home_width', '150'),
  );
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_home_height'] = array(
  '#type' => 'textfield',
  '#title' => t('Set the home height'),
  '#description' => t('Allows you to define an independent \'home\' element where the backLava defaults to or can be sent to. This can be used to define a unique starting and/or resting place for the backLava upon leaving the parent element.'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_home_height', '30'),
  );
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_return_home'] = array(
  '#type' => 'select',
  '#title' => t('Set the return home feature'),
  '#options' => array('true' => 'True', 'false' => 'False'),
  '#description' => t('Adjusts behavior of the backLava element when the the mouse leaves the parent container. the default behavior of \'false\' causes the backLava element to stay on the active menu items after it is first triggered. this feature respects the returnDelay parameter, if set. this feature overrides the autoReturn parameter.'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_return_home', 'false'),
  );
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_auto_resize'] = array(
  '#type' => 'select',
  '#title' => t('Set the auto resize feature'),
  '#options' => array('true' => 'True', 'false' => 'False'),
  '#description' => t('Triggers the selectedLava mouseenter event when the window is resized. Setting autoResize to true causes the backLava element to reposition and change dimensions if the resizing the screen changes the shape of the lavaLamp. autoResize is best used with the target option. Default is false for efficiency as this feature is new and seldom used.'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_auto_resize', 'false'),
  );
  
  $form['vt_lavalamp_plugin_root']['vt_lavalamp_include_margins'] = array(
  '#type' => 'select',
  '#title' => t('Include Margins'),
  '#options' => array('true' => 'True', 'false' => 'False'),
  '#description' => t('expands the hover .backLava element to include the margins of the target element. Best used in combination with the target and container options.'),
  '#default_value' => vt_lavalamp_get_default($data,'vt_lavalamp_include_margins', 'false'),
  );
  $form['#submit'][] = 'vt_lavalamp_admin_settings_submit';
  return system_settings_form($form);
}


function vt_lavalamp_admin_settings_submit($form, &$form_state) {
	unset($form_state['values']['submit'], $form_state['values']['form_build_id'], $form_state['values']['form_token'], $form_state['values']['form_id'], $form_state['values']['op']);
	variable_set('vt_lavalamp', serialize($form_state['values']));
}
	