# Dream-11

<h4>Implement a Dream 11 Application wherein the users are supposed to choose the players to form the team and calculate points based on the player’s performance. A team's Total points are calculated by summing the player’s points and deciding the winner among the users who gets the highest points over a single match.</h4>

<ul>
    <li>The user can choose any Sports league (Football League, Basketball League, IPL League).</li>
    <li>After choosing any league, the console displays the live match between two teams randomly from the choosen league.</li>
    <li>The user creates a team from set of players belonging to both teams.</li>
    <li>The user can choose the players from the given list os playersbased on player skills.</li>
    <li>The captain of the team is chosen and the points of the captain are doubled.</li>
    <li>The points of each player are calculated and the team's total points are calculated by summing the player’s points.</li>
    <li>The total points of each user are compared and the user with the maximum Total points is awarded as Winner.</li>
</ul>

<h2>Example of choosing IPL</h2>
<table border="1">
  <tr>
    <th>Test case number</th>
    <th>Test case description</th>
    <th>Input</th>
    <th>Expected output</th>
    <th>Test status</th>
  </tr>
  <tr>
    <td>1</td>
    <td>Users entering different league choice</td>
    <td>1,2,3 choice</td>
    <td>Warning to enter 3 i.e. to enter the choice for IPL league.</td>
    <td>PASS</td>
  </tr>
  <tr>
    <td>2</td>
    <td>User1 selects the best team.</td>
    <td>Both users will be selecting their teams.</td>
    <td>The calculated points of User 1 will be higher than User 2. So, User 1 will be declared the winner.</td>
    <td>PASS</td>
  </tr>
  <tr>
    <td>3</td>
    <td>User 2 selects the best team.</td>
    <td>Both users will be selecting their teams.</td>
    <td>The calculated points of User 2 will be higher than User 1. So, User 2 will be declared the winner.</td>
    <td>PASS</td>
  </tr>
  <tr>
    <td>4</td>
    <td>Both users select the same team.</td>
    <td>Both users will be selecting their teams.</td>
    <td>The calculated points of User 1 and User 2 will be the same. There are no winners in this case.</td>
    <td>PASS</td>
  </tr>
</table>
