<?php
$conn = mysqli_connect("localhost","root","","college");
if (!$conn){
    die("DB connection failed".mysqli_connect_error());
}
$result = mysqli_query($conn,"select * from students order by id desc");
if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $email = $_POST['email'];
    $sql = "UPDATE students SET name='$name', email='$email' WHERE id=$id";
    if ($conn->query($sql)) {
        echo "Record updated successfully!";
    } else {
        echo "Error updating record: " . $conn->error;
    }
}
if(isset($_POST["submit"])){
    $name = $_POST["name"];
    $email = $_POST["email"];
    $sql = "insert into students (name, email) values('$name','$email')";
    mysqli_query($conn, $sql);
}
if (isset($_GET['id'])) { $id = $_GET['id']; mysqli_query($conn, "DELETE FROM students WHERE id=$id"); echo "Record deleted!<br>"; }
// $result = $conn->query("SELECT * FROM students");
$result = mysqli_query($conn,"select * from students order by id desc");
?>
<!DOCTYPE html>
<html>
<head>
<title>Insert, View, Update, Delete</title>
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
    <table border="1" cellpadding="5">
        <tr><th>ID</th><th>Name</th><th>Email</th><th colspan="2">Action</th></tr>
        <?php while($row = $result->fetch_assoc()) { ?>
        <tr>
            <td><?= $row['id'] ?></td>
            <td><?= $row['name'] ?></td>
            <td><?= $row['email'] ?></td>
            <td><a href="?edit=<?= $row['id'] ?>">Edit</a></td>
            <td><a href="?id=<?=$row['id']?>">Delete</a></td>
        </tr>
        <?php } ?>
    </table>
    <?php
    // Show update form if edit is clicked
    if (isset($_GET['edit'])) {
        $id = $_GET['edit'];
        $row = $conn->query("SELECT * FROM students WHERE id=$id")->fetch_assoc();
        ?>
        <h2>Update Student</h2>
        <form method="post">
            <input type="hidden" name="id" value="<?= $row['id'] ?>">
            Name: <input type="text" name="name" value="<?= $row['name'] ?>" required> <br><br>
            Email: <input type="email" name="email" value="<?= $row['email'] ?>" required><br><br>
            <input type="submit" name="update" value="Update">
        </form>
    <?php } ?>
</body>
</html>