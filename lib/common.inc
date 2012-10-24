<?
require_once( $_SERVER['DOCUMENT_ROOT'] . "/lib/db_conn_mysql.inc");

function a($a)
{
	{
		echo "<pre>";
		print_r($a);
		echo "</pre>";
	}
}
CLASS COMMON
{
	public $DB;
	protected $Ajax = false;

	function __construct()
	{
		$this->DB = new DB_DECO;
		$this->DB->connect();
	}

	function __destruct() 
	{
		if( isset($DB) )
			$this->DB->close();
	}

	function init($Bool)
	{
		$this->Ajax = $Bool;
		$this->httpheaders();
	}

	protected function httpheaders()
	{   
		ini_set('default_charset', 'utf-8');
 
		if ($this->Ajax)
		{   
			header("Content-type: text/json; charset=utf-8");
			header('Expires: -365d');
			header('Cache-Control: no-cache, must-revalidate');
			header('Pragma: no-cache');
		}   
		else
		{   
			header('Content-type: text/html; charset=utf-8');
		}   
 
		header('Cache-Control: public');
	}

	function SqlProtect($str)
	{
		return htmlspecialchars(mysql_real_escape_string(trim($str)), ENT_NOQUOTES, "UTF-8");
	}

	/************************************************************************************/

	/* DB 트랜잭션 */

	function SqlTransaction()
	{
		$this->DB->query("BEGIN WORK");
	}

	function SqlCommit()
	{
		$this->DB->query("COMMIT");
	}

	function SqlRollback()
	{
		$this->DB->query("ROLLBACK");
	}

	/************************************************************************************/

	/************************************************************************************/
	/* 변수 체크 */

	function CheckValue($str, $regular)
	{
		if( strlen($str) < 1 )
			return false;
		preg_match_all($regular, $str, $temp_str_array); 
		$temp_str = implode('', $temp_str_array[0]);

		if($str != $temp_str)
			return false; 
		else
			return true;
	}

	function CheckEmail($str)
	{
		if( strlen($str) < 1 )
			return false;
		$regular = "/^[_0-9a-zA-Z-]+(\.[_0-9a-zA-Z-]+)*@[0-9a-zA-Z-]+(\.[0-9a-zA-Z-]+)+$/";
		preg_match_all($regular, $str, $temp_str_array); 
		$temp_str = implode('', $temp_str_array[0]);

		if($str != $temp_str)
			return false; 
		else
			return true;
	}

	function CheckNumber($str)
	{
		if( strlen($str) < 1 )
			return false;
		preg_match_all("/^[0-9]*$/", $str, $temp_str_array); 
		$temp_str = implode('', $temp_str_array[0]);

		if($str != $temp_str)
			return false; 
		else
			return true;
	}
}
?>
