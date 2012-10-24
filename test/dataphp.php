<?php
	header("Content-Type: text/html; charset=UTF-8");
	$con = mysql_connect("localhost","root","deco123");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	$select = mysql_select_db("deco", $con);
	if(!$select){
		echo("select error");
	}
	
	mysql_query('set names utf8');

	$file_line = file("placedata.txt");
	$size = sizeof($file_line);
	for($i=0; $i<$size; $i++){
		$tmp = $file_line[$i];
		$array_string = explode("&", $tmp);

		$name = $array_string[0];
		$category = $array_string[1];
		$address = $array_string[2];
		$phone = $array_string[3];
		$price = $array_string[4];
		$time = $array_string[5];
		$holiday = $array_string[6];
		$parking = $array_string[7];
		$description = $array_string[8];
		$score = $array_string[9];
		$area = $array_string[10];
		$reg_date = $array_string[11];
		$is_thumbexist = $array_string[12];
		$pic_count = $array_string[13];

	
			
			$query = "INSERT INTO place(name, category, address, phone, price, time, holiday, parking, description, area, reg_date, pic_count) VALUES('$name', '$category', '$address', '$phone', '$price', '$time', '$holiday', '$parking', '$description', '$area', '$reg_date', '$pic_count')";
			
			$result = mysql_query($query);
			if(!$result){
				echo("Error");
			}
	}
	/*
	if($file_ptr){
		mysql_query("INSERT INTO Persons (FirstName, LastName, Age) 
		VALUES ('Peter', 'Griffin', '35')");
		mysql_query("INSERT INTO Persons (FirstName, LastName, Age) 
		VALUES ('Glenn', 'Quagmire', '33')");
		
	}
	else{
		echo("File open fail");
	}
	*/
	mysql_close($con);
?>
