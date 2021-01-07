<?php

// localhost
define('DB_HOST', 'localhost');
define('DB_USER', 'root');
define('DB_PASS', 'password');
define('DB_NAME', 'bam');

// automatic global variables to use within applicatoin
$current_page = explode('/', $_SERVER['REQUEST_URI']);
