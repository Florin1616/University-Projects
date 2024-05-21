<?php
include 'connection.php';

// Query to fetch distinct countries
$sql = "SELECT DISTINCT country FROM destinations";
$result = mysqli_query($connection, $sql);

$countries = [];
if ($result) {
    while ($row = mysqli_fetch_assoc($result)) {
        $countries[] = $row['country'];
    }
} else {
    echo "Error: " . mysqli_error($connection);
}

// Close database connection
mysqli_close($connection);

// Output the countries array
echo json_encode($countries);
?>
