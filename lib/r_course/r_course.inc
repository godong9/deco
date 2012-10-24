<?
require_once( $_SERVER['DOCUMENT_ROOT'] . "/lib/common.inc");

CLASS RCOURSE EXTENDS COMMON
{
	/*
		getMyArea
		- 추천코스 메뉴의 나의 주변 코스 리스트를 가져오는 함수
		params (파라미터)
		- 없음.
		2012.10.23 정용기 생성
	*/
	function getMyArea($params)
	{
		$select_query = "SELECT
									name, 
									category, 
									address, 
									phone, 
									price, 
									time, 
									holiday, 
									parking, 
									description, 
									area, 
									reg_date, 
									pic_count 
								FROM 
									place 
								LIMIT 
									10";
		$this->DB->query($select_query);
		$i=0;
		while($row = $this->DB->next_fetch_array())
		{
			$array[$i]['name'] = $row['name'];
			$array[$i]['category'] = $row['category'];
			$array[$i]['address'] = $row['address'];
			$array[$i]['phone'] = $row['phone'];
			$array[$i]['price'] = $row['price'];
			$array[$i]['time'] = $row['time'];
			$array[$i]['holiday'] = $row['holiday'];
			$array[$i]['parking'] = $row['parking'];
			$array[$i]['description'] = $row['description'];
			$array[$i]['area'] = $row['area'];
			$array[$i]['reg_date'] = $row['reg_date'];
			$array[$i]['pic_count'] = $row['pic_count'];
			$i++;
		};
		return $array;
	}
}

?>