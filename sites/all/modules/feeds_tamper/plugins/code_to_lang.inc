<?php

/**
 * @file
 * Convert a language name to ISO code.
 */

$plugin = array(
  'form' => 'feeds_tamper_code_to_lang_form',
  'callback' => 'feeds_tamper_code_to_lang_callback',
  'name' => 'Language Code  to ISO language',
  'multi' => 'loop',
  'category' => 'Other',
  'default description' => 'Convert language code to  language',
);

function feeds_tamper_code_to_lang_form($importer, $element_key, $settings) {
  $form = array();

 $form['reduce_method'] = array(
    '#type' => 'radios',
    '#title' => t('Converts this field from a language name string to the two/three character ISO 396-1/-2 code.'),
    '#options' => array(
      'first' => t('Use Iso 639-1'),
      'second' => t('Use Iso 639-2'), ),
    '#required' => TRUE,
    '#default_value' => isset($settings['reduce_method']) ? $settings['reduce_method'] : NULL,
  );

  return $form;
}

function feeds_tamper_code_to_lang_callback($result, $item_key, $element_key, &$field, $settings, $source) {

 static $languages_list = array();

  if (empty($languages_list)) {
   
    switch ($settings['reduce_method']) {
     case 'first':           
      $languages_list =  array_languages_396_1a();
      $lng_new = array_flip($languages_list);
      break;
     case 'second':
      $languages_list =  array_languages_396_2a();
      $lng_new = array_flip($languages_list);
     break;
    }

    	array_walk($lng_new, '_feeds_tamper_code_to_lang_strtolower');

   
  }

  //$check = array();
  
  //$check = array_flip($languages_list);  

  // Trim whitespace, set to lowercase.
  $language = t(drupal_strtolower(trim($field)));


 
 // If it's already a valid language code, leave it alone.
  if (in_array($language,  $lng_new)) {
     $field =  $language;
    return;
  }




 
 if (isset($lng_new[$language])) {
    
   // $languages_list = array_flip($languages_list);
    $field = $lng_new[$language];
   
 }
  else {
    // If lang name cannot be found, return nothing.
    $field = '';

  }

}

/**
 * Callback for array_walk().
 */
function _feeds_tamper_code_to_lang_strtolower(&$word) {
  $word = drupal_strtolower($word);
}


function array_languages_396_1a(){
     $lang_new  = array();

    $lang_new = array( 
'abkhaz' => 'ab',
'afar' => 'aa',
'afrikaans' => 'af',
'akan' => 'ak',
'albanian' => 'sq',
'amharic' => 'am',
'arabic' => 'ar',
'aragonese' => 'an',
'armenian' => 'hy',
'assamese' => 'as',
'avaric' => 'av',
'avestan' => 'ae',
'aymara' => 'ay',
'azerbaijani' => 'az',
'bambara' => 'bm',
'bashkir' => 'ba',
'basque' => 'eu',
'belarusian' => 'be',
'bengali bangla' => 'bn',
'bihari' => 'bh',
'bislama' => 'bi',
'bosnian' => 'bs',
'breton' => 'br',
'bulgarian' => 'bg',
'burmese' => 'my',
'catalan' => 'ca',
'chamorro' => 'ch',
'chechen' => 'ce',
'chichewa chewa nyanja' => 'ny',
'chinese' => 'zh',
'chuvash' => 'cv',
'cornish' => 'kw',
'corsican' => 'co',
'cree' => 'cr',
'croatian' => 'hr',
'czech' => 'cs',
'danish' => 'da',
'divehi maldivian' => 'dv',
'dutch' => 'nl',
'dzongkha' => 'dz',
'english' => 'en',
'esperanto' => 'eo',
'estonian' => 'et',
'ewe' => 'ee',
'faroese' => 'fo',
'fijian' => 'fj',
'finnish' => 'fi',
'french' => 'fr',
'fula fulahpulaar pular' => 'ff',
'galician' => 'gl',
'georgian' => 'ka',
'german' => 'de',
'greek (modern)' => 'el',
'guaraní' => 'gn',
'gujarati' => 'gu',
'haitian haitian creole' => 'ht',
'hausa' => 'ha',
'hebrew (modern)' => 'he',
'herero' => 'hz',
'hindi' => 'hi',
'hiri motu' => 'ho',
'hungarian' => 'hu',
'interlingua' => 'ia',
'indonesian' => 'id',
'interlingue' => 'ie',
'irish' => 'ga',
'igbo' => 'ig',
'inupiaq' => 'ik',
'ido' => 'io',
'icelandic' => 'is',
'italian' => 'it',
'inuktitut' => 'iu',
'japanese' => 'ja',
'javanese' => 'jv',
'kalaallisut greenlandic' => 'kl',
'kannada' => 'kn',
'kanuri' => 'kr',
'kashmiri' => 'ks',
'kazakh' => 'kk',
'khmer' => 'km',
'kikuyu gikuyu' => 'ki',
'kinyarwanda' => 'rw',
'kyrgyz' => 'ky',
'komi' => 'kv',
'kongo' => 'kg',
'korean' => 'ko',
'kurdish' => 'ku',
'kwanyama kuanyama' => 'kj',
'latin' => 'la',
'luxembourgishletzeburgesch' => 'lb',
'ganda' => 'lg',
'limburgish limburgan limburger' => 'li',
'lingala' => 'ln',
'lao' => 'lo',
'lithuanian' => 'lt',
'luba-katanga' => 'lu',
'latvian' => 'lv',
'manx' => 'gv',
'macedonian' => 'mk',
'malagasy' => 'mg',
'malay' => 'ms',
'malayalam' => 'ml',
'maltese' => 'mt',
'māori' => 'mi',
'marathi (marāṭhī)' => 'mr',
'marshallese' => 'mh',
'mongolian' => 'mn',
'nauru' => 'na',
'navajo navaho' => 'nv',
'northern ndebele' => 'nd',
'nepali' => 'ne',
'ndonga' => 'ng',
'norwegian bokmål' => 'nb',
'norwegian nynorsk' => 'nn',
'norwegian' => 'no',
'nuosu' => 'ii',
'southern ndebele' => 'nr',
'occitan' => 'oc',
'ojibwe ojibwa' => 'oj',
'old church slavonic church slavonic old bulgarian' => 'cu',
'oromo' => 'om',
'oriya' => 'or',
'ossetian ossetic' => 'os',
'panjabi punjabi' => 'pa',
'pāli' => 'pi',
'persian (farsi)' => 'fa',
'polish' => 'pl',
'pashtopushto' => 'ps',
'portuguese' => 'pt',
'quechua' => 'qu',
'romansh' => 'rm',
'kirundi' => 'rn',
'romanian' => 'ro',
'russian' => 'ru',
'sanskrit (saṁskṛta)' => 'sa',
'sardinian' => 'sc',
'sindhi' => 'sd',
'northern sami' => 'se',
'samoan' => 'sm',
'sango' => 'sg',
'saraiki seraiki siraiki' => 'sk',
'serbian' => 'sr',
'scottish gaelic gaelic' => 'gd',
'shona' => 'sn',
'sinhala sinhalese' => 'si',
'slovak' => 'sk',
'slovene' => 'sl',
'somali' => 'so',
'southern sotho' => 'st',
'spanish' => 'es',
'sundanese' => 'su',
'swahili' => 'sw',
'swati' => 'ss',
'swedish' => 'sv',
'tamil' => 'ta',
'telugu' => 'te',
'tajik' => 'tg',
'thai' => 'th',
'tigrinya' => 'ti',
'tibetan standard tibetan central' => 'bo',
'turkmen' => 'tk',
'tagalog' => 'tl',
'tswana' => 'tn',
'tonga (tonga islands)' => 'to',
'turkish' => 'tr',
'tsonga' => 'ts',
'tatar' => 'tt',
'twi' => 'tw',
'tahitian' => 'ty',
'uyghur' => 'ug',
'ukrainian' => 'uk',
'urdu' => 'ur',
'uzbek' => 'uz',
'venda' => 've',
'vietnamese' => 'vi',
'volapük' => 'vo',
'walloon' => 'wa',
'welsh' => 'cy',
'wolof' => 'wo',
'western frisian' => 'fy',
'xhosa' => 'xh',
'yiddish' => 'yi',
'yoruba' => 'yo',
'zhuang chuang' => 'za',
'zulu' => 'zu',
 );

//$lang_new = array(	'english' => 'en', 'Italian' => 'it',);

//Exchanges all keys with their associated values in an array
// $lang_new = array_flip($lang_new);

 return  $lang_new;  
}


function array_languages_396_2a(){
	
    $lang_new  = array();
    

    $lang_new = array(
'abkhaz' => 'abk',
'afar' => 'aar',
'afrikaans' => 'afr',
'akan' => 'aka',
'albanian' => 'sqi',
'amharic' => 'amh',
'arabic' => 'ara',
'aragonese' => 'arg',
'armenian' => 'hye',
'assamese' => 'asm',
'avaric' => 'ava',
'avestan' => 'ave',
'aymara' => 'aym',
'azerbaijani' => 'aze',
'bambara' => 'bam',
'bashkir' => 'bak',
'basque' => 'eus',
'belarusian' => 'bel',
'bengali bangla' => 'ben',
'bihari' => 'bih',
'bislama' => 'bis',
'bosnian' => 'bos',
'breton' => 'bre',
'bulgarian' => 'bul',
'burmese' => 'mya',
'catalan' => 'cat',
'chamorro' => 'cha',
'chechen' => 'che',
'chichewa chewa nyanja' => 'nya',
'chinese' => 'zho',
'chuvash' => 'chv',
'cornish' => 'cor',
'corsican' => 'cos',
'cree' => 'cre',
'croatian' => 'hrv',
'czech' => 'ces',
'danish' => 'dan',
'divehi dhivehi maldivian' => 'div',
'dutch' => 'nld',
'dzongkha' => 'dzo',
'english' => 'eng',
'esperanto' => 'epo',
'estonian' => 'est',
'ewe' => 'ewe',
'faroese' => 'fao',
'fijian' => 'fij',
'finnish' => 'fin',
'french' => 'fra',
'fula pulaar  pular' => 'ful',
'galician' => 'glg',
'georgian' => 'kat',
'german' => 'deu',
'greek (modern)' => 'ell',
'guaraní' => 'grn',
'gujarati' => 'guj',
'haitian haitian creole' => 'hat',
'hausa' => 'hau',
'hebrew (modern)' => 'heb',
'herero' => 'her',
'hindi' => 'hin',
'hiri motu' => 'hmo',
'hungarian' => 'hun',
'interlingua' => 'ina',
'indonesian' => 'ind',
'interlingue' => 'ile',
'irish' => 'gle',
'igbo' => 'ibo',
'inupiaq' => 'ipk',
'ido' => 'ido',
'icelandic' => 'isl',
'italian' => 'ita',
'inuktitut' => 'iku',
'japanese' => 'jpn',
'javanese' => 'jav',
'kalaallisut greenlandic' => 'kal',
'kannada' => 'kan',
'kanuri' => 'kau',
'kashmiri' => 'kas',
'kazakh' => 'kaz',
'khmer' => 'khm',
'kikuyu gikuyu' => 'kik',
'kinyarwanda' => 'kin',
'kyrgyz' => 'kir',
'komi' => 'kom',
'kongo' => 'kon',
'korean' => 'kor',
'kurdish' => 'kur',
'kwanyama kuanyama' => 'kua',
'latin' => 'lat',
'luxembourgish letzeburgesch' => 'ltz',
'ganda' => 'lug',
'limburgish limburgan limburger ' => 'lim',
'lingala' => 'lin',
'lao' => 'lao',
'lithuanian' => 'lit',
'luba-katanga' => 'lub',
'latvian' => 'lav',
'manx' => 'glv',
'macedonian' => 'mkd',
'malagasy' => 'mlg',
'malay' => 'msa',
'malayalam' => 'mal',
'maltese' => 'mlt',
'māori' => 'mri',
'marathi (marāṭhī)' => 'mar',
'marshallese' => 'mah',
'mongolian' => 'mon',
'nauru' => 'nau',
'navajo navaho' => 'nav',
'northern ndebele' => 'nde',
'nepali' => 'nep',
'ndonga' => 'ndo',
'norwegian bokmål' => 'nob',
'norwegian nynorsk' => 'nno',
'norwegian' => 'nor',
'nuosu' => 'iii',
'southern ndebele' => 'nbl',
'occitan' => 'oci',
'ojibwe ojibwa' => 'oji',
'old church slavonic church slavonic , old bulgarian' => 'chu',
'oromo' => 'orm',
'oriya' => 'ori',
'ossetian ossetic ' => 'oss',
'panjabi punjabi' => 'pan',
'pāli' => 'pli',
'persian (farsi)' => 'fas',
'polish' => 'pol',
'pashto pushto' => 'pus',
'portuguese' => 'por',
'quechua' => 'que',
'romansh' => 'roh',
'kirundi' => 'run',
'romanian' => 'ron',
'russian' => 'rus',
'sanskrit (saṁskṛta)' => 'san',
'sardinian' => 'srd',
'sindhi' => 'snd',
'northern sami' => 'sme',
'samoan' => 'smo',
'sango' => 'sag',
'saraiki , seraiki , siraiki' => 'skr',
'serbian' => 'srp',
'scottish gaelic , gaelic' => 'gla',
'shona' => 'sna',
'sinhala  sinhalese' => 'sin',
'slovak' => 'slk',
'slovene' => 'slv',
'somali' => 'som',
'southern sotho' => 'sot',
'spanish' => 'spa',
'sundanese' => 'sun',
'swahili' => 'swa',
'swati' => 'ssw',
'swedish' => 'swe',
'tamil' => 'tam',
'telugu' => 'tel',
'tajik' => 'tgk',
'thai' => 'tha',
'tigrinya' => 'tir',
'tibetan standard , tibetan , central' => 'bod',
'turkmen' => 'tuk',
'tagalog' => 'tgl',
'tswana' => 'tsn',
'tonga (tonga islands)' => 'ton',
'turkish' => 'tur',
'tsonga' => 'tso',
'tatar' => 'tat',
'twi' => 'twi',
'tahitian' => 'tah',
'uyghur' => 'uig',
'ukrainian' => 'ukr',
'urdu' => 'urd',
'uzbek' => 'uzb',
'venda' => 'ven',
'vietnamese' => 'vie',
'volapük' => 'vol',
'walloon' => 'wln',
'welsh' => 'cym',
'wolof' => 'wol',
'western frisian' => 'fry',
'xhosa' => 'xho',
'yiddish' => 'yid',
'yoruba' => 'yor',
'zhuang chuang' => 'zha',
'zulu' => 'zul',
 		);
//Exchanges all keys with their associated values in an array
//$lang_new = array_flip($lang_new);

 return  $lang_new;
}

