<?php
$conn = mysqli_connect("localhost","root","","college");
if (!$conn){
    die("DB connection failed".mysqli_connect_error());
}
if(isset($_POST["submit"])){
    $name = $_POST["name"];
    $email = $_POST["email"];
    $sql = "insert into students (name, email) values('$name','$email')";
    mysqli_query($conn, $sql);
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Expt 4 - Insert & View</title>
</head>
<body>
    <h2>Insert Student</h2>
    <form method="post">
    <label for="email">Name: </label>
    <input type="text" name="name" placeholder="Enter your name" required>
    <br>
    <label for="email">Email: </label>
    <input type="email" name="email" placeholder="Enter your email" required>
    <br>
    <input type="submit" name="submit" value="Submit">
    </form>
    <h2>Student Records</h2>
    <table border="1" cellpadding="8">
        <tr><th>ID</th><th>Name</th><th>Email</th></tr>
        <?php
        $result = mysqli_query($conn,"select * from students order by id desc");
        if(!$result){
            die("Query Failed".mysqli_error($conn));
        }
        while ($row = mysqli_fetch_assoc($result)){
            echo"<tr>
            <td>{$row['id']}</td>
            <td>".htmlspecialchars($row['name'])."</td>
            <td>".htmlspecialchars($row['email'])."</td>
            </tr>";
        }
        ?>
    </table>
</body>
</html>