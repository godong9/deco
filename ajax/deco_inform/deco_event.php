<?
	require_once( $_SERVER['DOCUMENT_ROOT'] . "/lib/deco_inform/deco_inform.inc");

	$DECOINFORM = new DECOINFORM();
	$DECOINFORM->init(true);

	$params = array();
	$array = $DECOINFORM->getDecoEvent($params);
	echo json_encode($array);
?>
