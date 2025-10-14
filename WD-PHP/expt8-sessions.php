<?php
session_start();
$message = "";
// SESSION OPERATIONS
if (isset($_POST['set'])) {
$_SESSION['username'] = $_POST['sname'];
$message = "Session set successfully!";
}
if (isset($_POST['view'])) {
$message = isset($_SESSION['username'])
? "Session retrieved successfully!"
: "No session found!";
}
// Sessions Update and Delete
if (isset($_POST['update'])) {
if (isset($_SESSION['username'])) {
$_SESSION['username'] = $_POST['sname'];
$message = "Session updated successfully!";
} else {
$message = "No session to update!";
}
}
if (isset($_POST['delete'])) {
unset($_SESSION['username']);
$message = "Session deleted successfully!";
}
?>
<!DOCTYPE html>
<html>
<head>
<title>Sessions Operations in PHP using HTML</title>
<style>
table { border-collapse: collapse; width: 40%; margin-top: 15px; }
th, td { border: 1px solid black; padding: 8px; text-align: center; }
th { background: #f2f2f2; }
p { font-weight: bold; color: green; }
</style>
</head>
<body>
<h2>PHP Session Operations</h2>
<form method="post">
<input type="text" name="sname" placeholder="Enter session value">
<br><br>
<button type="submit" name="set">Set Session</button>
<button type="submit" name="view">View Session</button>
<button type="submit" name="update">Update Session</button>
<button type="submit" name="delete">Delete Session</button>
</form>
<?php
// Display message
if (!empty($message)) echo "<p>$message</p>";
// Display session in table if exists
if (isset($_SESSION['username'])) {
echo "
<table>
<tr><th>Session Name</th><th>Session Value</th></tr>
<tr><td>username</td><td>{$_SESSION['username']}</td></tr>
</table>";
}
?>
</body>
</html>