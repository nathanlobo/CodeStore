<?php
print"Nathan";
echo'<br><br>Image Below<br><img src="img.jpg" width="200" height="200">';
echo'<br><a href="https://www.youtube.com/ElectroProjects">My YouTube Channel</a>';
echo'<br><br>Image With Link Below<br><a href="https://www.youtube.com/ElectroProjects"><img src="img.jpg"></a>';

echo"<br><br>Using For Loop <br>";
for($i=1;$i<=10;$i++)
{echo"number is $i<br>";}

echo"<br>For Loop with break<br>";
for($i=1;$i<=10;$i++){
	if($i==6){break;}
	echo"Number is $i<br>";
}
echo"<br>For Loop with continue: Skips number 6<br>";
for($i=1;$i<=10;$i++){
	if($i==6){continue;}
	echo"Number is $i<br>";
}

echo"<br>Text using variable";
$name="Nathan Lobo";
$age=20;
echo"<br>My Name is $name & My age is $age";
?>