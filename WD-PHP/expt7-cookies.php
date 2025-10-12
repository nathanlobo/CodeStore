<?php
$message = "";
$cookieData = [];
// -------------------------- COOKIE OPERATIONS ----------------------------
// Set Cookie
if (isset($_POST['set'])) {
    $name = $_POST['cname'];
    setcookie("username", $name,time() + (60*5),"/"); // Valid for 5 mins
    $message = "Cookie has been set successfully!";
}
// View Cookie
if (isset($_POST['view'])) {
    if (isset($_COOKIE['username'])) {
        $cookieData['username'] = $_COOKIE['username'];
        $message = "Cookie retrieved successfully!";
    } else {
        $message = "No cookie found!";
    }
}
// Update Cookie
if (isset($_POST['update'])) {
    $newname = $_POST['cname'];
    if (isset($_COOKIE['username'])) {
        setcookie("username", $newname, time() + (60*5),"/");
        $message = "Cookie has been updated successfully!";
    } else {
        $message ="No cookie to update!";
    }
}
// Delete Cookie
if (isset($_POST['delete'])) {
    setcookie("username", "", time() - 3600, "/"); // Expire in past
    $message = "Cookie has been deleted!";
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>PHP Cookies Example</title>
    <style>
        table {
            border-collapse: collapse;
            width: 40%;
            margin-top: 15px;
        }
        th, td {
            border: 1px soild black;
            padding: 8px;
            text-align: center;
        }
        th {
            background: #f2f2f2;
        }
        .msg {
            margin: 10px 0;
            color: green;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <h2>Cookie Operations (PHP + HTML)</h2>
    <form method="post">
        <input type="text" name="cname" placeholder="Enter Cookie Value"><br><br>
        <button type="submit" name="set">Set cookie</button>
        <button type="submit" name="view">View cookie</button>
        <button type="submit" name="update">Update cookie</button>
        <button type="submit" name="delete">Delete cookie</button>
    </form>
    <?php
        if (!empty($message)) {
            echo"<p><b>$message</b></p>";
        }
        if (isset($_COOKIE['username'])) {
            echo "<table border='1' cellpadding='8' cellspacing='0'>
                  <tr><th>Cookie Name</th><th>Cookie Value</th></tr>
                  <tr><td>Username</td><td>{$_COOKIE['username']}</td></tr>
                  </table>";
        }
    ?>
</body>
</html>