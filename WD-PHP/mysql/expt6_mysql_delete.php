<?php
$conn = mysqli_connect("localhost", "root", "","College");
// delete if id is passed
if (isset($_GET['id'])) {
    $id = $_GET['id']; 
    mysqli_query($conn, "DELETE FROM students WHERE id=$id"); 
    echo "Record deleted!<br>";
}
// fetch all records
$result = mysqli_query($conn, query: "SELECT * FROM students");
echo "<table border='1'>
<tr><th>ID</th><th>Name</th><th>Email</th><th>Action</th></tr>";
while ($row = mysqli_fetch_assoc($result)) {
echo "<tr>
<td>".$row['id']."</td>
<td>".$row['name']."</td>
<td>".$row['email']."</td>
<td><a href='?id=".$row['id']."'>Delete</a></td>
</tr>";
}
echo "</table>";
?>