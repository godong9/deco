<?
	require_once( $_SERVER['DOCUMENT_ROOT'] . "/lib/r_course/user_recommend.inc");

	$USERRECOMMEND = new USERRECOMMEND();
	$USERRECOMMEND->init(true);

	$params = array();
	$array = $USERRECOMMEND->getUserRecommend($params);
	echo json_encode($array);
?>
