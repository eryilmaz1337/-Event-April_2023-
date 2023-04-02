<?php

function whoWins(string $p, string $c) {
    if ($p == $c)
        printf("Draw! The computer chose %s.\n", $c);
    else if ($p == "rock" && $c == "paper")
        printf("Sorry, you lost. The computer chose %s.\n", $c);
    else if ($p == "rock" && $c == "scissors")
        printf("Congratulations! You won! The computer chose %s.\n", $c);
    else if ($p == "paper" && $c == "scissors")
        printf("Sorry, you lost. The computer chose %s.\n", $c);
    else if ($p == "paper" && $c == "rock")
        printf("Congratulations! You won! The computer chose %s.\n", $c);
    else if ($p == "scissors" && $c == "rock")
        printf("Sorry, you lost. The computer chose %s.\n", $c);
    else if ($p == "scissors" && $c == "paper")
        printf("Congratulations! You won! The computer chose %s.\n", $c);
    else
        printf("Unknown choice : %s\n", $p);
}

echo "Choose rock, paper, or scissors: ";
$input = trim(fgets(STDIN));
$cc = rand(0,2);
whoWins(strtolower($input), $cc == 0 ? "rock" : ($cc == 1 ? "paper" : "scissors"));
?>

