$(document).ready(function() {
    $('#add-destination-form').on('submit', function(e) {
        e.preventDefault();
        $.ajax({
            type: 'POST',
            url: $(this).attr('action'),
            data: $(this).serialize(),
            dataType: 'json',
            success: function(response) {
                if (response.success) {
                    $('#message').html('<div class="alert alert-success">' + response.success + '</div>');
                } else if (response.error) {
                    $('#message').html('<div class="alert alert-danger">' + response.error + '</div>');
                }
            }
        });
    });
});


function fetchDestinations(page = 1) {
    $.ajax({
        type: 'GET',
        url: 'get_all_destinations.php',
        data: { page: page },
        dataType: 'json',
        success: function(response) {
            $('#destinations').empty();
            $.each(response.destinations, function(index, destination) {
                $('#destinations').append(
                    '<div class="col-md-4">' +
                    '<div class="card mb-4">' +
                    '<div class="card-body">' +
                    '<h5 class="card-title">' + destination.name + '</h5>' +
                    '<h6 class="card-subtitle mb-2 text-muted">' + destination.country + '</h6>' +
                    '<p class="card-text">' + destination.description + '</p>' +
                    '<p class="card-text"><small class="text-muted">Tourist Targets: ' + destination.tourist_targets + '</small></p>' +
                    '<p class="card-text"><small class="text-muted">Estimated Cost: ' + destination.estimated_cost + '</small></p>' +
                    '<a href="../modify-destination.html?id=' + destination.id + '" class="btn btn-warning">Modify</a>'+                    
                    '<a href="#" class="btn btn-danger delete-button" data-id="' + destination.id + '">Delete</a>' +
                    '</div>' +
                    '</div>' +
                    '</div>'
                );
            });
            renderPagination(response.pages, response.page);
        },
        error: function(error) {
            console.error('Error:', error);
        }
    });
}

function renderPagination(totalPages, currentPage) {
    $('#paginationContainer').empty();
    for (let i = 1; i <= totalPages; i++) {
        let activeClass = (i === currentPage) ? 'active' : '';
        $('#paginationContainer').append(
            '<li class="page-item ' + activeClass + '"><a class="page-link" href="#">' + i + '</a></li>'
        );
    }
}

$(document).ready(function() {
    fetchDestinations();

    $(document).on('click', '.page-link', function(e) {
        e.preventDefault();
        let page = $(this).text();
        fetchDestinations(page);
    });

    $(document).on('click', '.delete-button', function(e) {
        e.preventDefault();
        var id = $(this).data('id');
        deleteDestination(id);
    });
});

$(document).on('click', '.delete-button', function(e) {
    e.preventDefault();
    var id = $(this).data('id');
    deleteDestination(id);
});


function deleteDestination(id) {
    $.ajax({
        type: 'POST',
        url: 'delete-destination.php',
        data: { id: id },
        dataType: 'json',
        success: function(response) {
            if (response.success) {
                $('#message').html('<div class="alert alert-success">' + response.success + '</div>');
                fetchDestinations();
            } else if (response.error) {
                $('#message').html('<div class="alert alert-danger">' + response.error + '</div>');
            }
        },
        error: function(error) {
            console.error('Error:', error);
        }
    });
}


$(document).ready(function() {
    var countries = JSON.parse('{{countries}}');
    var destinations = JSON.parse('{{destinations}}');
    var pages = parseInt('{{pages}}', 10);
    var error = '{{error}}';

    $.each(countries, function(index, country) {
        $('#countrySelect').append($('<option>', { 
            value: country,
            text : country 
        }));
    });

    $.each(destinations, function(index, destination) {
        $('#destinationContainer').append(
            '<div class="col-md-4">' +
            '<div class="card mb-4">' +
            '<div class="card-body">' +
            '<h5 class="card-title">' + destination.name + '</h5>' +
            '<h6 class="card-subtitle mb-2 text-muted">' + destination.country + '</h6>' +
            '<p class="card-text">' + destination.description + '</p>' +
            '</div>' +
            '</div>' +
            '</div>'
        );
    });

    for (var i = 1; i <= pages; i++) {
        $('#paginationContainer').append('<a href="?page=' + i + '">' + i + '</a>');
    }

    if (error) {
        $('#message').html('<div class="alert alert-danger">' + error + '</div>');
    }

    $('#countrySelect').change(function() {
        $('#countryForm').submit();
    });
});




$(document).ready(function() {
    const urlParams = new URLSearchParams(window.location.search);
    const id = urlParams.get('id');

    console.log('ID:', id);

    if (id) {
        $.ajax({
            type: 'GET',
            url: 'Backend/get_destination.php', 
            data: { id: id },
            dataType: 'json',
            success: function(response) {
                if (response.success) {
                    const destination = response.destination;
                    $('#id').val(destination.id);
                    $('#name').val(destination.name);
                    $('#country').val(destination.country);
                    $('#description').val(destination.description);
                    $('#tourist_targets').val(destination.tourist_targets);
                    $('#estimated_cost').val(destination.estimated_cost);
                } else if (response.error) {
                    $('#message').html('<div class="alert alert-danger">' + response.error + '</div>');
                }
            },
            error: function(error) {
                console.error('Error:', error);
                $('#message').html('<div class="alert alert-danger">An error occurred while fetching the destination details.</div>');
            }
        });
    } else {
        $('#message').html('<div class="alert alert-danger">No destination ID provided.</div>');
    }

    $('#modify-destination-form').on('submit', function(e) {
        e.preventDefault();
        $.ajax({
            type: 'POST',
            url: $(this).attr('action'),
            data: $(this).serialize(),
            dataType: 'json',
            success: function(response) {
                if (response.success) {
                    $('#message').html('<div class="alert alert-success">' + response.success + '</div>');
                } else if (response.error) {
                    $('#message').html('<div class="alert alert-danger">' + response.error + '</div>');
                }
            },
            error: function(error) {
                console.error('Error:', error);
                $('#message').html('<div class="alert alert-danger">An error occurred while updating the destination.</div>');
            }
        });
    });
});
