<?php
include 'connection.php';

header('Content-Type: application/json');

if (isset($_GET['id'])) {
    $id = intval($_GET['id']);

    $sql = "SELECT * FROM destinations WHERE id = $id";
    $result = mysqli_query($connection, $sql);

    if ($result && mysqli_num_rows($result) > 0) {
        $destination = mysqli_fetch_assoc($result);
        echo json_encode(['success' => true, 'destination' => $destination]);
    } else {
        echo json_encode(['success' => false, 'error' => 'Destination not found.']);
    }
} else {
    echo json_encode(['success' => false, 'error' => 'No ID provided.']);
}

mysqli_close($connection);
?>
