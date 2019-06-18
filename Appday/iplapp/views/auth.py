from django.views import View
from iplapp.models import Matches,Deliveries
from django.shortcuts import render,redirect
from django import forms
from django.shortcuts import get_object_or_404
from iplapp.forms.auth import LoginForm,SignupForm
from django.urls import resolve
from django.contrib import messages
from django.contrib.auth import authenticate,logout,login
from django.contrib.auth.models import User


def logout_user(request):
    logout(request)
    return redirect('loginform')


class LoginView(View):
    def get(self, request, *args, **kwargs):
           #if request.user.is_authenticated:
               #return redirect('colleges_html')

           form=LoginForm()
           return render(request,template_name='iplapp/login.html',context={'form':form})

    def post(self,request,*args,**kwargs):
          form=LoginForm(request.POST)
          if form.is_valid():
              user=authenticate(
                  request,
                  username=form.cleaned_data['username'],
                  password=form.cleaned_data['password'],
              )
              if user is not None:
                   login(request,user)
                   return redirect("seasons_html")
              else:
                  messages.error(request, 'username or password not correct')
                  return redirect('loginform')

          return render(
                request,
                template_name='iplapp/login.html',context={'form':form}
          )


class SignupView(View):
    def get(self,request,*args,**kwargs):
          form=SignupForm()
          return render(request,template_name='iplapp/signup.html',context={'form':form})

    def post(self,request,*args,**kwargs):
           form=SignupForm(request.POST)
           if form.is_valid():
               user=User.objects.create_user(**form.cleaned_data)
               user.save()

               if user is not None:
                   login(request,user)
                   return redirect('loginform')
           else:
               return render(
                   request,
                   template_name='iplapp/signup.html', context={'form': form})
