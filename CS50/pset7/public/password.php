<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["oldpassword"]))
        {
            apologize("You haven't entered your password.");
        }
        else if (empty($_POST["newpassword"]))
        {
            apologize("You haven't entered your new password.");
        }
        else if($_POST["confirmation"] != $_POST["newpassword"])
        {
            apologize("Try again");
        }
        
        $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        if (count($rows) == 1)
        {
            // first (and only) row
            $row = $rows[0];

            // compare hash of user's input against hash that's in database
            if (crypt($_POST["oldpassword"], $row["hash"]) == $row["hash"])
            {
               // Now change the password
               $change = CS50::query("UPDATE users SET hash=?",crypt($_POST["newpassword"]));
               render("password_changed.php",["title" => "Sucess!!"]);
               
            }
            else
            {
                apologize("Invalid Password");
            }
        }
    }
    
    else
    {
        // else render form
        render("password_form.php", ["title" => "Change Password"]);
    }
    
?>
