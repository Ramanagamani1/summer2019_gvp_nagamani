"""homeproject URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.conf import settings

from django.urls import include, path  # For django versions from
from homeproject import *
from todoapp import views
from todoapp.views.todolist import *
from todoapp.views.auth import *
from todoapp.views.todoitem import *


urlpatterns = [
    path('admin/', admin.site.urls),
    path('todolists/',views.todolist.TodoListView.as_view(),name="todolists_html"),
    path('todolists/<int:id>/',views.todolist.TodoListView.as_view(),name="todoitems_html"),
    path("todolists/add/",AddTodoListView.as_view(),name="addtodolists"),
    path(r"todolists/<int:pk>/edit",AddTodoListView.as_view(),name="edit_todolist"),
    path(r"todolists/<int:pk>/delete",AddTodoListView.as_view(),name="delete_todolist"),
    path("todolists/<int:pk>/add/",AddTodoItemView.as_view(),name="addtodoitem"),
    path("todoitems/<int:pk>/edit",AddTodoItemView.as_view(),name="edit_todoitem"),
    path("todoitems/<int:pk>/delete", AddTodoItemView.as_view(),name="delete_todoitem"),
    path(r'login/', LoginView.as_view(), name="loginform"),
    path(r'signup/', SignupView.as_view(), name="signupform"),
    path(r'logout/', logout_user, name="logout"),

]

if settings.DEBUG:
    import debug_toolbar
    urlpatterns = [
        path('__debug__/', include(debug_toolbar.urls)),

        # For django versions before 2.0:
        # url(r'^__debug__/', include(debug_toolbar.urls)),

    ] + urlpatterns