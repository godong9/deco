<?
	header("Content-Type: text/html; charset=UTF-8");
	$con = mysql_connect("localhost","root","deco123");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	$select = mysql_select_db("deco", $con);
	if(!$select){
		echo("Error");
	}
	mysql_query('set names utf8');

	$query = "SELECT name, category, address, phone, price, time, holiday, parking, description, area, reg_date, pic_count FROM place LIMIT 10";
			
	$result = mysql_query($query, $con);
	if(!$result){
		echo("Error");
	}
	
	$fields = mysql_num_fields($result);
	$j=0;
	while($row = mysql_fetch_row($result)){
		$array[$j]['name'] = $row[0];
		$array[$j]['category'] = $row[1];
		$array[$j]['address'] = $row[2];
		$array[$j]['phone'] = $row[3];
		$array[$j]['price'] = $row[4];
		$array[$j]['time'] = $row[5];
		$array[$j]['holiday'] = $row[6];
		$array[$j]['parking'] = $row[7];
		$array[$j]['description'] = $row[8];
		$array[$j]['area'] = $row[9];
		$array[$j]['reg_date'] = $row[10];
		$array[$j]['pic_count'] = $row[11];
		
		$j++;
	};
	mysql_close($con);
/*	
	$array[0]['name'] = iconv("CP949", "UTF-8", "apple");
	$array[0]['ceo'] = iconv("CP949", "UTF-8", "팀 쿡");
	$array[0]['content'] = iconv("CP949", "UTF-8", "미국 기업");
	
	$array[1]['name'] = iconv("CP949", "UTF-8", "samsung");
	$array[1]['ceo'] = iconv("CP949", "UTF-8", "신종길");
	$array[1]['content'] = iconv("CP949", "UTF-8", "한국 기업");
*/
	$return_data = json_encode($array);
	
	echo $return_data;
?>
