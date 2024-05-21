<?php
// Include the database connection file
include 'connection.php';

header('Content-Type: application/json');

// Check if the form was submitted and the id field was filled in
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['id'])) {
    // Get the ID of the destination from the POST data
    $id = intval($_POST['id']);

    // Get the new details from the POST data
    $name = mysqli_real_escape_string($connection, $_POST['name']);
    $country = mysqli_real_escape_string($connection, $_POST['country']);
    $description = mysqli_real_escape_string($connection, $_POST['description']);
    $tourist_targets = mysqli_real_escape_string($connection, $_POST['tourist_targets']);
    $estimated_cost = floatval($_POST['estimated_cost']);

    $sql = "UPDATE destinations SET name = '$name', country = '$country', description = '$description', tourist_targets = '$tourist_targets', estimated_cost = $estimated_cost WHERE id = $id";
    if (mysqli_query($connection, $sql)) {
        echo json_encode(['success' => 'Destination updated successfully.']);
    } else {
        echo json_encode(['error' => 'Error updating destination: ' . mysqli_error($connection)]);
    }
} else {
    echo json_encode(['error' => 'Invalid request or missing ID.']);
}
mysqli_close($connection);
?>
