function getData() {
	var data_url = "data.php";
		$.ajax({
			type: "POST",
			dataType: 'json',
			contentType: "application/json; charset=utf-8",
			url: data_url,
			cache: false,
			async: true,
			success: onSuccess
		});
			
		function onSuccess(data) {
			for( idx in data ) {
					var name = data[idx].name; 
					var price = data[idx].price;
					var phone = data[idx].phone;
					var tmp = "<li>"+name+" / "+price+" / "+phone+"</li>";
					$('ul').append(tmp).listview('refresh');
			}		
		}
}