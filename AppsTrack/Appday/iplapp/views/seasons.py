from django.views import View
from iplapp.models import Matches,Deliveries
from django.shortcuts import render,redirect
from django import forms
from django.shortcuts import get_object_or_404
from django.urls import resolve
from django.contrib.auth.mixins import LoginRequiredMixin
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from django.db.models import *


class ListMatchesView(View):
    def get(self, request, *args, **kwargs):
         if kwargs:
               matches_played = Matches.objects.filter(**kwargs)
               paginator = Paginator(matches_played, 8)  # posts per page
               page = request.GET.get('page')
               try:
                   queryset = paginator.page(page)
               except PageNotAnInteger:
                   queryset = paginator.page(1)
               except EmptyPage:
                   queryset = paginator.page(paginator.num_pages)
               return render(
                   request,
                   template_name="iplapp/seasons.html",
                   context={
                       'season':kwargs['season'],
                       'matches_played': matches_played,
                       "queryset": queryset,
                       'user_permissions': request.user.get_all_permissions(),
                       'title': 'All seasons | IPL App'
                   }
               )



         queryset=Matches.objects.filter(season="2019")
         return render(
              request,
              template_name="iplapp/seasons.html",
              context={
                  'queryset': queryset,
                  'user_permissions': request.user.get_all_permissions(),
                  'title': 'All seasons | IPL App'
              }
          )

class ViewMatchDetails(LoginRequiredMixin,View):
    login_url='/login/'
    def get(self, request, *args, **kwargs):
         if kwargs:
             season_details=Matches.objects.get(id=kwargs['id'])
             match_details=Deliveries.objects.filter(match__id=kwargs['id'])
             topscorers_list=Deliveries.objects.values('batsman','batting_team').annotate(score=Sum('batsman_runs')).order_by('-score').filter(match_id=kwargs['id'])[:3]
             wickettakers_list=Deliveries.objects.values('bowler','bowling_team').annotate(count=Count('dismissal_kind')).order_by('-count').filter(match_id=kwargs['id']).exclude(dismissal_kind__exact='')[:3]
             innings1=Deliveries.objects.filter(match__id=kwargs['id']).filter(inning="1")
             innings2=Deliveries.objects.filter(match__id=kwargs['id']).filter(inning="2")
             return render(
                 request,
                 template_name="iplapp/individualmatch.html",
                 context={
                     'season': kwargs['season'],
                     'season_details':season_details,
                     'match_details': match_details,
                     'topscorers_list':topscorers_list,
                     'wickettakers_list':wickettakers_list,
                     'innings1':innings1,
                     'innings2':innings2,
                     'user_permissions': request.user.get_all_permissions(),
                     'title': 'All seasons | IPL App'
                 }
             )


class PointsTablePage(LoginRequiredMixin,View):
    def get(self, request, *args, **kwargs):
        if kwargs:
            winner_list = Matches.objects.values_list('winner').annotate(count=Count('winner')).filter(result="normal").filter(season=kwargs['season'])
            tie_list=Matches.objects.values_list('team1','team2').annotate(count=Count('result')).filter(result="tie").filter(season=kwargs['season'])
            winner_list=dict(winner_list)
            for key in winner_list.keys():
                winner_list[key]*=2;
            for x in tie_list:
                if x[0] in winner_list.keys():
                    winner_list[x[0]]+=1
                else:
                    winner_list[x[0]]=1
            for x in tie_list:
                if x[1] in winner_list.keys():
                    winner_list[x[1]]+=1
                else:
                    winner_list[x[1]]=1
            points_info=[(key,winner_list[key]) for key in winner_list.keys()]
            return render(
                request,
                template_name="iplapp/pointstable.html",
                context={
                    'season': kwargs['season'],
                    'points_info':points_info,
                }
            )
        else:
            winner_list = Matches.objects.values_list('winner').annotate(count=Count('winner')).filter(
                result="normal").filter(season="2019")
            tie_list = Matches.objects.values_list('team1', 'team2').annotate(count=Count('result')).filter(
                result="tie").filter(season="2019")
            winner_list = dict(winner_list)
            for key in winner_list.keys():
                winner_list[key] *= 2;
            for x in tie_list:
                if x[0] in winner_list.keys():
                    winner_list[x[0]] += 1
                else:
                    winner_list[x[0]] = 1
            for x in tie_list:
                if x[1] in winner_list.keys():
                    winner_list[x[1]] += 1
                else:
                    winner_list[x[1]] = 1
            points_info = [(key, winner_list[key]) for key in winner_list.keys()]
            return render(
                request,
                template_name="iplapp/pointstable.html",
                context={
                    'season':kwargs['season'],
                    'points_info': points_info,
                }
            )
