from django.db import models

# Create your models here.

class Matches(models.Model):
     match_id=models.CharField(max_length=128,unique=True)
     season=models.CharField(max_length=128)
     city=models.CharField(max_length=128)
     date=models.CharField(max_length=128)
     team1=models.CharField(max_length=128)
     team2=models.CharField(max_length=128)
     toss_winner=models.CharField(max_length=128)
     toss_decision=models.CharField(max_length=128)
     result=models.CharField(max_length=128)
     dl_applied=models.CharField(max_length=128)
     winner=models.CharField(max_length=128)
     win_by_runs=models.TextField()
     win_by_wickets=models.TextField()
     player_of_match=models.CharField(max_length=128)
     venue=models.CharField(max_length=128)
     umpire1=models.CharField(max_length=128)
     umpire2=models.CharField(max_length=128)
     umpire3=models.CharField(max_length=128)

     def __str__(self):
         return self.season



class Deliveries(models.Model):
     match=models.ForeignKey(Matches, on_delete=models.CASCADE,to_field="match_id")
     inning=models.CharField(max_length=128)
     batting_team=models.CharField(max_length=128)
     bowling_team=models.CharField(max_length=128)
     over=models.CharField(max_length=128)
     ball=models.CharField(max_length=128)
     batsman=models.CharField(max_length=128)
     non_striker=models.CharField(max_length=128)
     bowler=models.CharField(max_length=128)
     is_super_over=models.CharField(max_length=128)
     wide_runs=models.CharField(max_length=128)
     bye_runs=models.CharField(max_length=128)
     legbye_runs=models.CharField(max_length=128)
     noball_runs=models.CharField(max_length=128)
     penalty_runs=models.CharField(max_length=128)
     batsman_runs=models.CharField(max_length=128)
     extra_runs=models.CharField(max_length=128)
     total_runs=models.CharField(max_length=128)
     player_dismissed=models.CharField(max_length=128)
     dismissal_kind=models.CharField(max_length=128)
     fielder=models.CharField(max_length=128)

     def __str__(self):
         return self.inning