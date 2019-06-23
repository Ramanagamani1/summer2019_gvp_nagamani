"""appday URL Configuration

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
from django.urls import path
from django.contrib import admin
from django.conf import settings
from django.conf.urls.static import static
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
from django.urls import include
from iplapp.views.seasons import ListMatchesView,ViewMatchDetails,PointsTablePage
from iplapp.views.auth import *

urlpatterns = [
    path('admin/', admin.site.urls),
    path('seasonspage/',ListMatchesView.as_view(),name="seasons_html"),
    path('seasonspage/<str:season>/',ListMatchesView.as_view(),name="seasondetails_html"),
    path('seasonspage/<str:season>/match/<int:id>/',ViewMatchDetails.as_view(),name="matchdetails_html"),
    path('points/<str:season>/',PointsTablePage.as_view(),name="pointstable_html"),
    path(r'login/', LoginView.as_view(), name="loginform"),
    path(r'signup/', SignupView.as_view(), name="signupform"),
    path(r'logout/', logout_user, name="logout")

]


if settings.DEBUG:
    import debug_toolbar
    urlpatterns = [

        path('__debug__/', include(debug_toolbar.urls)),

        # For django versions before 2.0:
        # url(r'^__debug__/', include(debug_toolbar.urls)),



    ] + urlpatterns