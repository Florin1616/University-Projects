<?php
include 'connection.php';

$country = $_GET['country'];

$sql = "SELECT * FROM destinations WHERE country = ?";
$stmt = mysqli_prepare($connection, $sql);
mysqli_stmt_bind_param($stmt, 's', $country);
mysqli_stmt_execute($stmt);
$result = mysqli_stmt_get_result($stmt);

$destinations = [];
if ($result) {
    while ($row = mysqli_fetch_assoc($result)) {
        $destinations[] = $row;
    }
} else {
    echo "Error: " . mysqli_error($connection);
}

mysqli_close($connection);

echo json_encode($destinations);
?>