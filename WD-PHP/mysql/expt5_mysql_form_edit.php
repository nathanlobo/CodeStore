<?php
// Database connection
$conn = new mysqli("localhost", "root", "", "College");
if ($conn->connect_error) { die("Connection failed: " .$conn->connect_error); }
// Update logic
if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $email = $_POST['email'];
    $sql = "UPDATE students SET name='$name', email='$email' WHERE id=$id";
    if ($conn->query($sql)) {
        echo "Record updated successfully!";
    } else {
        echo "Error updating record: " . $conn->error;
    }}
// Fetch all records
$result = $conn->query("SELECT * FROM students");
?>
<!DOCTYPE html>
<html>
<head>
<title>Update Student</title>
</head>
<body>
    <h2>Student Records</h2>
    <table border="1" cellpadding="5">
        <tr><th>ID</th><th>Name</th><th>Email</th><th>Action</th></tr>
        <?php while($row = $result->fetch_assoc()) { ?>
        <tr>
            <td><?= $row['id'] ?></td>
            <td><?= $row['name'] ?></td>
            <td><?= $row['email'] ?></td>
            <td><a href="?edit=<?= $row['id'] ?>">Edit</a></td>
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