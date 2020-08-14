<?php

    // find user_error()
    $user = User::user_find_by_id($_SESSION['user_id']);
?>
<div class="alert alert-warning text-center site-disclaimer" role="alert">Welcom to Bill Account Manager. This is a demo site built with OOP PHP and MySQLi by <a href="https://imaginedesigndevelop.com" target="_blank">Imagine Design Develop</a>. Feel free to reach out for a in depth tour of this application and backend system.</div>
<nav class="navbar navbar-default" role="navigation">
    <div class="container">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <a class="navbar-brand" href="welcome.php"><span>Bill Account Manager</span></a>
        </div>
        <!-- Collect the nav links, forms, and other content for toggling -->
        <div class="collapse navbar-collapse navbar-ex1-collapse">
            <ul class="nav navbar-nav navbar-right">
                <?php if ($session->is_signed_in()){ ?>

                    <li class="<?=((
                    $_GET['view'] == 'home' ||
                    $_GET['view'] == 'accounts' ||
                    $_GET['view'] == 'bills' ||
                    $_GET['view'] == 'archived' ||
                    $_GET['view'] == 'payments' ||
                    $_GET['view'] == 'notes' ||
                    $_GET['view'] == 'tasks' ||
                    $_GET['view'] == 'edit'
                    ) ? 'active' : '')?>"><a href="index.php?view=home"><i class="fa fa-home"></i> BAM Manager</a></li>
                    <li class="<?=(($_GET['view'] == 'account') ? 'active' : '')?>"><a href="index.php?view=account"><i class="fa fa-cogs" aria-hidden="true"></i> Your Account</a></li>
                    <li><a href="logout.php"><i class="fa fa-sign-out" aria-hidden="true"></i> Logout</a></li>

                <?php }else{?>
                    <li><a href="login.php"><i class="fa fa-sign-in" aria-hidden="true"></i> Login</a></li>
                <?php } ?>
            </ul>
         </div>
        <!-- /.navbar-collapse -->
    </div>
    <!-- /.container -->
</nav>
