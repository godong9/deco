<?
	require_once( $_SERVER['DOCUMENT_ROOT'] . "/lib/r_course/deco_choice.inc");

	$DECOCHOICE = new DECOCHOICE();
	$DECOCHOICE->init(true);

	$params = array();
	$array = $DECOCHOICE->getDecoChoice($params);
	echo json_encode($array);
?>
