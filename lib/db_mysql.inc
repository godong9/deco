<?php

	class DB_Sql
	{
		var $Host     = "";
		var $Database = "";
		var $User     = "";
		var $Password = "";

		var $Link_ID  = 0;
		var $Query_ID = 0;
		var $Record   = array();
		var $Row;

		var $Errno    = 0;
		var $Error    = "";

		var $Auto_free = 0;     ## Set this to 1 for automatic mysql_free_result()

		function connect()
		{
			if ( 0 == $this->Link_ID )
			{
				$this->Link_ID = mysql_connect ( $this->Host, $this->User, $this->Password, false, 2);

				if ( !$this->Link_ID)
				{
					$this->halt("Link-ID == false, pconnect failed");
				}

				if ( !mysql_query ( sprintf("use %s",$this->Database),$this->Link_ID ) )
				{
					$this->halt("cannot use database ".$this->Database);
				}

				mysql_query("set names utf8");
			}
		}

		function query($Query_String)
		{
			$this->connect();

			$this->Query_ID = mysql_query($Query_String,$this->Link_ID);
			$this->Row   = 0;
			$this->Errno = mysql_errno();
			$this->Error = mysql_error();

			if ( !$this->Query_ID )
			{
				$this->halt("Invalid SQL: ".$Query_String);
			}

			return $this->Query_ID;
		}

		function next_record()
		{
			$this->Record = mysql_fetch_array($this->Query_ID);
			$this->Row   += 1;
			$this->Errno = mysql_errno();
			$this->Error = mysql_error();

			$stat = is_array($this->Record);
			if ( !$stat && $this->auto_free )
			{
				mysql_free_result($this->Query_ID);
				$this->Query_ID = 0;
			}
			return $stat;
		}

		function next_fetch_array() 
		{
			if ( !$this->Link_ID )
				return false;

			#$this->Record = mysql_fetch_array($this->Query_ID, $this->Row++);
			$this->Record = mysql_fetch_array($this->Query_ID);

			$this->Errno = mysql_errno();
			$this->Error = mysql_error();

			$stat = is_array($this->Record);
			if ( !$stat )
			{
				mysql_free_result($this->Query_ID);
				$this->Query_ID = 0;
			}
			return $this->Record;
		}

		function seek ( $pos )
		{
			$status = mysql_data_seek($this->Query_ID, $pos);
			if ( $status )
				$this->Row = $pos;
			return;
		}

		function next_fetch_row()
		{
			if ( !$this->Link_ID )
				return false;

			$this->Record = @mysql_fetch_row($this->Query_ID, $this->Row++);

			$this->Error = mysql_error();
			$this->Errno = mysql_errno();

			$stat = is_array($this->Record);

			if ( !$stat )
			{
				mysql_free_result($this->Query_ID);
				$this->Query_ID = 0;
			}
			return $this->Record;
		}
		
		function insert_id()
		{
			return mysql_insert_id();			
		}

		function metadata($table)
		{
			$count = 0;
			$id    = 0;
			$res   = array();

			$this->connect();
			$id = @mysql_list_fields($this->Database, $table);

			if ( $id < 0 )
			{
				$this->Errno = mysql_errno();
				$this->Error = mysql_error();
				$this->halt("Metadata query failed.");
			}

			$count = mysql_num_fields($id);

			for ($i=0; $i<$count; $i++)
			{
				$res[$i]["table"] = mysql_field_table ($id, $i);
				$res[$i]["name"]  = mysql_field_name  ($id, $i);
				$res[$i]["type"]  = mysql_field_type  ($id, $i);
				$res[$i]["len"]   = mysql_field_len   ($id, $i);
				$res[$i]["flags"] = mysql_field_flags ($id, $i);
				$res["meta"][$res[$i]["name"]] = $i;
				$res["num_fields"]= $count;
			}

			mysql_free_result($id);
			return $res;
		}

		function affected_rows()
		{
			return mysql_affected_rows($this->Link_ID);
		}

		function num_rows()
		{
			return mysql_num_rows($this->Query_ID);
		}

		function num_fields()
		{
			return mysql_num_fields($this->Query_ID);
		}

		function nf()
		{
			return $this->num_rows();
		}

		function np()
		{
			print $this->num_rows();
		}

		function f($Name)
		{
			return $this->Record[$Name];
		}

		function p($Name)
		{
			print $this->Record[$Name];
		}

		function halt($msg)
		{
			printf("</td></tr></table><b>Database error:</b> %s<br>\n", $msg);
			printf("<b>MySQL Error</b>: %s (%s)<br>\n", $this->Errno, $this->Error);
			die("Session halted.");
		}

		function close()
		{
			mysql_close($this->Link_ID);
		}
	}
?>