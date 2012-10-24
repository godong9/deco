
function getContent(name)
{
	var data_url = "data.php";
	var select_name = name.value;
	$.ajax({
    type: "POST",
    dataType: 'json',
    contentType: "application/json; charset=utf-8",
    url: data_url,
    cache: false,
    async: true,
    success: onSuccess
  });
	
function onSuccess(data)
  {
    for( idx in data )
  	{
  		if(select_name == data[idx].name)
  		{
		  	var ceo = document.getElementById("price");
		  	ceo.setAttribute("value", data[idx].price);
		  	
		  	var content = document.getElementById("phone");
		  	content.setAttribute("value", data[idx].phone);
		  }
  	}
  }
}