import os
import csv
import click
import openpyxl

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'appday.settings')
import django

django.setup()
from iplapp.models import Matches,Deliveries
import MySQLdb as MS
@click.group()
def main():


    pass

@main.command()
def importdata():

    with open('matches.csv') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            if len(row)==0:
                continue
            p = Matches(match_id=row['id'],season=row['season'],city=row['city'],date=row['date'],team1=row['team1'],team2=row['team2'],toss_winner=row['toss_winner'],toss_decision=row['toss_decision'],result=row['result'],dl_applied=row['dl_applied'],winner=row['winner'],win_by_runs=row['win_by_runs'],win_by_wickets=row['win_by_wickets'],player_of_match=row['player_of_match'],venue=row['venue'],umpire1=row['umpire1'],umpire2=row['umpire2'],umpire3=row['umpire3'])
            p.save()


@main.command()
def importdeliveries():
    from iplapp.models import Deliveries
    with open('deliveries.csv') as csvfile:
        reader=csv.DictReader(csvfile)
        matches=Matches.objects.all()
        for row in reader:
            p=Deliveries(inning=row['inning'],batting_team=row['batting_team'],bowling_team=row['bowling_team'],over=row['over'],ball=row['over'],batsman=row['batsman'],non_striker=row['non_striker'],bowler=row['bowler'],is_super_over=row['is_super_over'],wide_runs=row['wide_runs'],bye_runs=row['bye_runs'],legbye_runs=row['legbye_runs'],noball_runs=row['noball_runs'],penalty_runs=row['penalty_runs'],batsman_runs=row['batsman_runs'],extra_runs=row['extra_runs'],total_runs=row['total_runs'],player_dismissed=row['player_dismissed'],dismissal_kind=row['dismissal_kind'],fielder=row['fielder'])
            for x in matches:
                if x.match_id==row['match_id']:
                    p.match=Matches.objects.get(match_id=x.match_id)
                    break
            p.save()



if __name__=='__main__':
    main()