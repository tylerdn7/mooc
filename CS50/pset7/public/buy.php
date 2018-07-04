<?php

    // configuration
    require("../includes/config.php"); 

    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("Stock symbol required.");
        }
        if (empty($_POST["shares"]))
        {
            apologize("YOu haven't put share amount.");
        }
        if (preg_match("/^\d+$/", $_POST["shares"])!=true)
        {
            apologize("Negative numbers are not allowed.");
        }
        // lookup symbol
        $stock = lookup($_POST["symbol"]);
        if ($stock===false)
        {
            apologize("Stock symbol invalid.");
        }
        else
        {
        // calculate purchase total
        $buy = $_POST["shares"] * $stock["price"];

        $transaction = 'BUY';
        
        $rows = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $cash = $rows[0]['cash'];   
            // check if enough cash
            if ($buy>$cash)
            {
                apologize("Not enough cash.");
            }
            else
            {
                // capitalize symbol
                $stock["symbol"] = strtoupper($stock["symbol"]);
                // update portfolio
                CS50::query("INSERT INTO portfolios (id, symbol, shares) VALUES (?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES (shares)", $_SESSION["id"], $stock["symbol"], $_POST["shares"]);
                
            // update cash
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $buy, $_SESSION["id"]);
            // update history
            CS50::query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $stock["symbol"], $_POST["shares"], $stock["price"]); 
            }
        // redirect to portfolio    
        redirect("/");
        }
    }
    else
    {
        render("buy_form.php", ["title" => "Buy"]);
    }

?>