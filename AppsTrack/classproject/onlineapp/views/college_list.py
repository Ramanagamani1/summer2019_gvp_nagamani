from django.shortcuts import render
from django.http import HttpResponse
from rest_framework.decorators import api_view
from rest_framework.response import Response
from onlineapp.models import College,Student,MockTest1
from onlineapp.serializers import CollegeSerializer,StudentSerializer
from rest_framework import status
from rest_framework.permissions import IsAuthenticated
from rest_framework.authentication import SessionAuthentication, BasicAuthentication,TokenAuthentication
from rest_framework.decorators import api_view, permission_classes,authentication_classes


@api_view(['GET','POST'])
@authentication_classes((SessionAuthentication, BasicAuthentication,TokenAuthentication))
@permission_classes((IsAuthenticated,))
def rest_CollegeList(request):
    if request.method == 'GET':
        college = College.objects.all()
        serializer = CollegeSerializer(college, many=True)
        return Response(serializer.data)
    elif request.method=='POST':
        serializer=CollegeSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


@api_view(['GET','POST','DELETE','PUT'])

@authentication_classes((SessionAuthentication, BasicAuthentication,TokenAuthentication))
@permission_classes((IsAuthenticated,))
def rest_CollegeDetails(request,**kwargs):
    college = College.objects.get(id=kwargs['id'])
    if request.method == 'GET':
        serializer = CollegeSerializer(college,many=False)
        return Response(serializer.data)

    elif request.method=='DELETE':
        college.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)

    elif request.method == 'PUT':
        serializer = CollegeSerializer(college, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)



