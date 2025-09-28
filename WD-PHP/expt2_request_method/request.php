<?php
if(isset($_REQUEST['myname'])){
	$name=$_REQUEST['myname'];
	echo"Hey! $name";
}else{
	echo"Email not found";}
?>