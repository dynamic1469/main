<?php
session_start();
// Include database connection details
$host = 'localhost'; // e.g., localhost
$username = 'root';
$password = 'Mysql@2023';
$dbname = 'your_database_name';

// Connect to MySQL server
$conn = new mysqli($host, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Function to safely handle user input
function sanitize_input($input)
{
    global $conn;
    return mysqli_real_escape_string($conn, trim($input));
}

// Check if the form was submitted for registration
if (isset($_POST["register"])) {
    // Sanitize and get the user input
    $username = sanitize_input($_POST["username"]);
    $password = sanitize_input($_POST["password"]);

    // Check if the username is already registered
    $check_query = "SELECT user_id FROM users WHERE username = '$username'";
    $check_result = $conn->query($check_query);

    if ($check_result->num_rows > 0) {
        // If username is already registered, display an error message
        echo "Username '$username' is already registered. Please choose a different username.";
    } else {
        // Hash the password before storing it
        $hashed_password = password_hash($password, PASSWORD_DEFAULT);

        // Insert user data into the database
        $sql = "INSERT INTO users (username, password) VALUES ('$username', '$hashed_password')";

        if ($conn->query($sql) === TRUE) {
            // Registration successful, redirect to a success page or show a success message
            echo "Registration successful.";
            $_SESSION['is_logged_in'] = 'true';
            $_SESSION['username'] = $username;
            header("Location: http://localhost/uthr/");
        } else {
            // If there was an error in registration, display an error message
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    }
}

// Check if the form was submitted for login
if (isset($_POST["login"])) {
    // Sanitize and get the user input
    $username = sanitize_input($_POST["username"]);
    $password = sanitize_input($_POST["password"]);

    // Fetch the hashed password from the database
    $sql = "SELECT user_id, password FROM users WHERE username = '$username'";
    $result = $conn->query($sql);

    if ($result->num_rows == 1) {
        $row = $result->fetch_assoc();
        $hashed_password = $row["password"];
        // Check if the provided password matches the stored hashed password
        if (password_verify($password, $hashed_password)) {
            // Login successful, redirect to a success page or show a success message
            echo "Login successful. Welcome, $username!";
            $_SESSION['is_logged_in'] = 'true';
            $_SESSION['username'] = $username;
            header("Location: http://localhost/uthr/");
        } else {
            // If password doesn't match, display an error message
            echo "Incorrect password. Please try again.";
            header("Location: http://localhost/uthr/wrong-password");
        }
    } else {
        // If user doesn't exist, display an error message
        echo "User not found. Please check your username.";
        header("Location: http://localhost/uthr/usernotfound");
    }
}

// Close the database connection
$conn->close();

echo json_encode(array('sessionValue' => $_SESSION['is_logged_in']));
?>
