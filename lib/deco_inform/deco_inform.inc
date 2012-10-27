<?
require_once( $_SERVER['DOCUMENT_ROOT'] . "/lib/common.inc");

CLASS DECOINFORM EXTENDS COMMON
{
	/*
		- 데코알림의 이벤트 리스트를 가져오는 함수
		params (파라미터)
		- 없음.
		2012.10.24 고동현 생성
	*/
	function getDecoEvent($params)
	{
		$select_query = "SELECT
									e.title,
									e.content,
									e.reg_date
								FROM 
									event AS e";
		$this->DB->query($select_query);
		$i=0;
		while($row = $this->DB->next_fetch_array())
		{
			$array[$i]['title'] = $row['title'];
			$array[$i]['content'] = $row['content'];
			$array[$i]['reg_date'] = $row['reg_date'];
			$i++;
		};
		return $array;
	}
}

?>