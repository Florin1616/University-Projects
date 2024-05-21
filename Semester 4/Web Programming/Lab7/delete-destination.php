<?php
include 'connection.php';

$id = $_POST['id'];

$sql = "DELETE FROM destinations WHERE id = $id";

if (mysqli_query($connection, $sql)) {
    echo json_encode(array('success' => 'Destination deleted successfully.'));
} else {
    echo json_encode(array('error' => "Error: " . $sql . "<br>" . mysqli_error($connection)));
}

mysqli_close($connection);
?>