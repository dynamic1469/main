<?php
session_start(); // Start the session
$_SESSION['logged_in'] = 'flase';

// Replace DB_HOST, DB_USERNAME, DB_PASSWORD, and DB_NAME with your database credentials
$connection = mysqli_connect("localhost", "root", "MYsql@2023", "test");

// Check connection
if (mysqli_connect_errno()) {
    die("Database connection failed: " . mysqli_connect_error());
}

// Registration form processing
if (isset($_POST['register'])) {
    $username = mysqli_real_escape_string($connection, $_POST['username']);
    $password = password_hash($_POST['password'], PASSWORD_BCRYPT);
    $hobby = mysqli_real_escape_string($connection, $_POST['hobby']);

    // Perform insert query to store user information in the database
    $query = "INSERT INTO users (username, password, hobby) VALUES ('$username', '$password', '$hobby')";

    if (mysqli_query($connection, $query)) {
    // Registration successful, you can redirect to a success page
         header("Location: http://localhost/uthr/");
         $_SESSION['logged_in'] = 'true';
   // Output the value of loggedin Variable as a JSON response
         header('Content-Type: application/json');
         echo json_encode($_SESSION['logged_in']);
        exit();
    } else {
        echo "Error: " . $query . "<br>" . mysqli_error($connection);
    }
}

// Login form processing
session_start();

if (isset($_POST['login'])) {
    $username = mysqli_real_escape_string($connection, $_POST['username']);
    $password = $_POST['password'];

    // Retrieve the hashed password and hobby from the database based on the given username
    $query = "SELECT id, password, hobby FROM users WHERE username='$username'";
    $result = mysqli_query($connection, $query);

    if ($result && mysqli_num_rows($result) > 0) {
        $row = mysqli_fetch_assoc($result);
        $hashedPassword = $row['password'];

        // Verify the password
        if (password_verify($password, $hashedPassword)) {
            $_SESSION['user_id'] = $row['id'];
            $_SESSION['user_hobby'] = $row['hobby'];
            // Login successful, redirect to the user's dashboard or home page
            header("Location: http://localhost/uthr/");
            // Set the variable in the session
            $_SESSION['logged_in'] = 'true';
            // Output the value of loggedin Variable as a JSON response
            header('Content-Type: application/json');
            echo json_encode($_SESSION['logged_in']);
            exit();
        } else {
            echo "Invalid password";
        }
    } else {
        echo "User not found";
    }
}
?>
