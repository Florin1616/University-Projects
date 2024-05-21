<?php
include 'connection.php';

// Get the page number from the query string, default to 1 if not provided
$page = isset($_GET['page']) ? (int)$_GET['page'] : 1;
$limit = 4; // Number of destinations per page
$offset = ($page - 1) * $limit;

$sql = "SELECT * FROM destinations LIMIT $limit OFFSET $offset";
$result = mysqli_query($connection, $sql);

if (mysqli_num_rows($result) > 0) {
    $destinations = array();
    while ($row = mysqli_fetch_assoc($result)) {
        $destinations[] = $row;
    }

    // Get the total number of destinations
    $countResult = mysqli_query($connection, "SELECT COUNT(*) as total FROM destinations");
    $totalCount = mysqli_fetch_assoc($countResult)['total'];

    echo json_encode(array(
        'destinations' => $destinations,
        'total' => $totalCount,
        'page' => $page,
        'pages' => ceil($totalCount / $limit)
    ));
} else {
    echo json_encode(array(
        'destinations' => array(),
        'total' => 0,
        'page' => 1,
        'pages' => 1
    ));
}

mysqli_close($connection);
?>
