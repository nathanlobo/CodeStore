<?php
$servername="localhost";
$username="root";
$password="";
$dbname="College";
$conn=new mysqli($servername,$username,$password,$dbname);
if($conn->connect_error){
	die("Connection failed:".$conn->connect_error);
}
echo "Connected";
$sql="INSERT INTO
students(name,email) 
VALUES('NATHAN','nathan@gmail.com')";
if($conn->query($sql)===TRUE)
{
	echo"<br>New Entry succesfully made";
}else{
	echo"<br>Error ".$sql."<br>".$conn->error;
}$conn->close();
?>