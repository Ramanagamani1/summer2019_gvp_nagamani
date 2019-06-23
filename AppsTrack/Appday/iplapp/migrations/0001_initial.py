# Generated by Django 2.2.1 on 2019-06-17 05:02

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Matches',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('season', models.CharField(max_length=128)),
                ('city', models.CharField(max_length=128)),
                ('date', models.DateField()),
                ('team1', models.CharField(max_length=128)),
                ('team2', models.CharField(max_length=128)),
                ('toss_winner', models.CharField(max_length=128)),
                ('toss_decision', models.CharField(max_length=128)),
                ('result', models.CharField(max_length=128)),
                ('dl_applied', models.CharField(max_length=128)),
                ('winner', models.CharField(max_length=128)),
                ('win_by_runs', models.TextField()),
                ('win_by_wickets', models.TextField()),
                ('player_of_match', models.CharField(max_length=128)),
                ('venue', models.CharField(max_length=128)),
                ('umpire1', models.CharField(max_length=128)),
                ('umpire2', models.CharField(max_length=128)),
                ('umpire3', models.CharField(max_length=128)),
            ],
        ),
        migrations.CreateModel(
            name='Deliveries',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('inning', models.CharField(max_length=128)),
                ('batting_team', models.CharField(max_length=128)),
                ('bowling_team', models.CharField(max_length=128)),
                ('over', models.CharField(max_length=128)),
                ('ball', models.CharField(max_length=128)),
                ('batsman', models.CharField(max_length=128)),
                ('non_striker', models.CharField(max_length=128)),
                ('bowler', models.CharField(max_length=128)),
                ('is_super_over', models.CharField(max_length=128)),
                ('wide_runs', models.CharField(max_length=128)),
                ('bye_runs', models.CharField(max_length=128)),
                ('legbye_runs', models.CharField(max_length=128)),
                ('noball_runs', models.CharField(max_length=128)),
                ('penalty_runs', models.CharField(max_length=128)),
                ('batsman_runs', models.CharField(max_length=128)),
                ('extra_runs', models.CharField(max_length=128)),
                ('total_runs', models.CharField(max_length=128)),
                ('player_dismissed', models.CharField(max_length=128)),
                ('dismissal_kind', models.CharField(max_length=128)),
                ('fielder', models.CharField(max_length=128)),
                ('match', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='iplapp.Matches')),
            ],
        ),
    ]