<?php

	// initialize page
	require_once('init.php');

	// check if user logged in
	if (!$session->is_signed_in()) { redirect('login.php'); }

	// make sure edit type is set
	if (!isset($_POST['edit'])) { redirect('index.php?view=home'); }


	// create url params
	$type = $_POST['edit'];
	$user_id = $_POST['user_id'];
	$id = $_POST['id'];

	// check if logged in user
	if ($user_id != $_SESSION['user_id']) { redirect('index.php?view=home'); }

	// run edit type
	if ($type == 'note') {

		// find note to edit
		$edit_note = Note::find_by_id($id);

		// if note found
		if ($edit_note) {

			$edit_note->note_title = $_POST['note_title'];
			$edit_note->note_body = $_POST['note_body'];

				// if bill saved
			if ($edit_note->save()) {

				// success message
				$session->message("Note was sccessfully saved.");

			}else{

				// error message
				$session->message("Note could not be saved.");

			}

		}

		// redirect back to bills
		redirect('index.php?view=notes');

	}elseif($type == 'pi'){

		// find user by edit
		$user = User::find_by_id($user_id);

		// if user found
		if ($user) {

			$user->first_name = $_POST['first_name'];
			$user->last_name = $_POST['last_name'];
			$user->address = $_POST['address'];
			$user->city = $_POST['city'];
			$user->state = $_POST['state'];
			$user->zip = $_POST['zip'];
			$user->subscribed = $_POST['subscribed'];

				// if user saved
			if ($user->save()) {

				// success message
				$session->message("Personal info was sccessfully saved.");

			}else{

				// success message
				$session->message("Personal info was sccessfully saved.");

			}

		}

		// redirect back to bills
		redirect('index.php?view=account');


	}elseif($type == 'notifications') {

        // find user by edit
        $user = User::find_by_id($user_id);

        $notifications = $_POST['notifications'];

		//heck if user already getting notifications
		$userNotifications = Notification::notifactions_for_users($user_id);
		if ($userNotifications){

            $updateNotifications = Notification::find_by_id($userNotifications->id);

            if (in_array('late_bills', $notifications)){
                $updateNotifications->late_bills = 1;
            }else{
                $updateNotifications->late_bills = 0;
			}

            if (in_array('upcoming_bills', $notifications)){
                $updateNotifications->upcoming_bills = 1;
            }else{
                $updateNotifications->upcoming_bills = 0;
            }

            $updateNotifications->save();

        }else{
            $newUserNotifications = new Notification;

            $newUserNotifications->user_id = $user_id;

            if (in_array('late_bills', $notifications)){
                $newUserNotifications->late_bills = 1;
            }

            if (in_array('upcoming_bills', $notifications)){
                $newUserNotifications->upcoming_bills = 1;
            }

            $newUserNotifications->save();
		}

        // success message
        $session->message("Notification settings where updated.");

        // redirect back to bills
        redirect('index.php?view=account');


    }else{

		// redirect back to home
		redirect('index.php?view=home');

	}

?>
