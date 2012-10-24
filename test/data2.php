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

	$query = "SELECT name, category, address, phone, price, time, holiday, parking, description, area, reg_date, pic_count FROM place LIMIT 100";
			
	for($i=0; $i<1; $i++){
		$result = mysql_query($query, $con);
	}

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

	$return_data = json_encode($array);
	
	echo $return_data;
?>