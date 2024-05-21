<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Vacation Manager</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
    <script src="../js/script.js"></script>
</head>
<body>
    <div class="container text-center">
        <h1>Vacation Manager</h1>
        <div class="row" style="margin-top: 200;">
            <div class="col-md-6 offset-md-3">
                <a href="../add-destination.html" class="btn btn-primary btn-lg btn-block mb-3">Add Destination</a>
                <a href="../browse-destinations.html" class="btn btn-success btn-lg btn-block mb-3">Browse destinations by country</a>
            </div>  
        </div>
        <div class="row" id="destinations"></div>
        <nav aria-label="Page navigation example">
            <ul class="pagination justify-content-center" id="paginationContainer"></ul>
        </nav>
    </div>
</body>
</html>
