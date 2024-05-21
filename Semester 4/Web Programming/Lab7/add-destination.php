<?php
include 'connection.php';

$name = $country = $description = $tourist_targets = $estimated_cost = '';
$error = '';
$success = '';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = htmlspecialchars($_POST['name']);
    $country = htmlspecialchars($_POST['country']);
    $description = htmlspecialchars($_POST['description']);
    $tourist_targets = htmlspecialchars($_POST['tourist_targets']);
    $estimated_cost = floatval($_POST['estimated_cost']);

    $sql = "INSERT INTO destinations (name, country, description, tourist_targets, estimated_cost) 
            VALUES ('$name', '$country', '$description', '$tourist_targets', '$estimated_cost')";
    
    if (mysqli_query($connection, $sql)) {
        $success = "Destination added successfully!";
    } else {
        $error = "Error: " . $sql . "<br>" . mysqli_error($connection);
    }
}

header('Content-Type: application/json');
echo json_encode(array('success' => $success, 'error' => $error));
?>