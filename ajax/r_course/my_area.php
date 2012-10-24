<?
	require_once( $_SERVER['DOCUMENT_ROOT'] . "/lib/r_course/r_course.inc");

	$RCOURSE = new RCOURSE();
	$RCOURSE->init(true);

	$params = array();
	$array = $RCOURSE->getMyArea($params);
	echo json_encode($array);
?>
