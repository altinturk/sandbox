<?php

	function executeQuery($SQLStr) {
		$servername = "<serverip>";
		$username = "<databaseuser>";
		$password = "<databasepassword>";
		$dbname = "<databasename>";

		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			die("Connection failed: " . $conn->connect_error);
		} 

		$result = $conn->query($SQLStr);
		$conn->close();
		return $result; 
	}


	function execQuery(){		
		// Create connection
		$conn = new mysqli($srv, $usr, $psw, $tbl);
		// Check connection
		if ($conn->connect_error) {
			die("Connection failed: " . $conn->connect_error);
		} 
		$sqlQuery = "SELECT * FROM DatabaseTable";
		$result = $conn->query($sqlQuery);
		//then do your thing

	}

	function saveData ($key, $value, $detail) {
		$sqlquery = "INSERT INTO DatabaseTable(col1, col2, col3) VALUES ('".$key."','".$value."','".$detail."')";
		$result = executeQuery($sqlquery);
		return $result; 
	}

	function databaseDump(){
		$result = executeQuery("SELECT * FROM DatabaseTable");
		echo "<table style='margin:0px auto;'><thead><tr><td width='40'>id</td><td width='150'>Type</td><td width='200'>State</td><td align='right'>Updated</td></tr></thead><tbody>";
		if ($result->num_rows > 0) {
			while($row = $result->fetch_assoc()) {
				echo "<tr><td>".$row["id"]."</td><td>" .$row["key"]."</td><td>" . $row["value"]."</td><td align='right'>" . $row["timestamp"] . "</td></tr>";
			}
		}
		else
			echo "<tr><td colspan=4>No results </td></tr>";
		echo "</tbody></table>";
		$conn->close();
	}

	function runCronTasks() {
		$last_run = 1;
		$result = executeQuery("SELECT detail FROM DatabaseTable");
		if ($result->num_rows > 0) {
			while($row = $result->fetch_assoc()) {
				$last_run = $row["detail"];
			}
		}
		if(time() > $last_run + (60 * 5)) { // 5 minutes
			$response = file_get_contents("http://www.page.com/api/init.php", false);
			// do meta tasks
			// save the last run time to a file, database, etc
		}
	}

	function getTurkishTimestamp () {
		date_default_timezone_set('Europe/Rome');
		$monthName = array("Ocak", "Şubat", "Mart", "Nisan", "Mayıs", "Haziran", "Temmuz", "Ağustos", "Eylül", "Ekim", "Kasım", "Aralık");
		$datestamp = date('d', time()) . " " . $monthName[(int)date('m',time())-1] . " " . date('Y, H:i', time());
		return $datestamp;
	}

	function get_https_content($url=NULL,$method="GET"){
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
		curl_setopt($ch, CURLOPT_VERBOSE, true);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($ch, CURLOPT_USERAGENT, 'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:31.0) Gecko/20100101 Firefox/31.0');
		curl_setopt($ch, CURLOPT_ENCODING ,"");
		curl_setopt($ch, CURLOPT_URL,$url);
		return curl_exec($ch);
	}

	function getFileFromURL($url, $filename) {
		$aContext = array('http' => array('request_fulluri' => true));
		$cxContext = stream_context_create($aContext);
		file_put_contents("php-getfile/$filename", file_get_contents($url, False, $cxContext));
	}
		
	function sendMail ($subject, $message) {
		$to      = '<insert email address>';
		$subject_ = 'Update - ' . $subject;
		$message_ = $message . '<hr> Timestamp: ' . date("Y-m-d H:i:s") ;


		$headers = 'MIME-Version: 1.0' . "\r\n";
		$headers .= 'Content-type: text/html; charset=utf-16' . "\r\n";
		$headers .= 'From: admin@server.com' . "\r\n" .
			'Reply-To: admin@server.com' . "\r\n" .
			'X-Mailer: PHP/' . phpversion();

		mail($to, $subject_, $message_, $headers);
	}
  
	function getJSONData($endpoint) {
		$apiurl = "https://www.jsonsource.com/"; 
		$response = get_https_content($apiurl .  $endpoint . "/");

		$DOM = new DOMDocument;
		$DOM->loadHTML($response);
		$items = $DOM->getElementsByTagName('script');
		$json = rtrim(str_replace("window._sharedData = ","", $items->item(1)->nodeValue),";");

		// from here on it's json manipulation
		$obj = json_decode($json);
		$following = $obj->entry_data->nodeElement[0]->node1->leaf;
	}

?>