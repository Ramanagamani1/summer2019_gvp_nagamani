from django.shortcuts import render
from django.http import HttpResponse
from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework.views import APIView
from onlineapp.models import College,Student,MockTest1
from onlineapp.serializers import CollegeSerializer,StudentSerializer,MockTest1Serializer,StudentDetailsSerializer
from rest_framework import status
from rest_framework.authentication import SessionAuthentication, BasicAuthentication
from rest_framework.permissions import IsAuthenticated
from rest_framework.authtoken.views import ObtainAuthToken
from rest_framework.authtoken.models import Token
from rest_framework.response import Response



class rest_StudentList(APIView):
     authentication_classes = (SessionAuthentication, BasicAuthentication)
     permission_classes = (IsAuthenticated,)
     def get(self,request,*args,**kwargs):
          college = College.objects.get(id=kwargs['id'])
          students=Student.objects.filter(college=college)
          serializer=StudentDetailsSerializer(students,many=True)
          return Response(serializer.data)

     def post(self,request,**kwargs):
         serializer=StudentDetailsSerializer(data=request.data,context={'cpk':kwargs['id']})
         if serializer.is_valid():
             serializer.save()
             return Response(serializer.data, status=status.HTTP_201_CREATED)
         return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)





class rest_StudentDetails(APIView):
    authentication_classes = (SessionAuthentication, BasicAuthentication)
    permission_classes = (IsAuthenticated,)
    def get(self,request,*args,**kwargs):
        student = Student.objects.get(id=kwargs['sid'])
        serializer=StudentDetailsSerializer(student,many=False)
        return Response(serializer.data)


    def put(self,request,*args,**kwargs):
        c = College.objects.get(id = kwargs['id'])
        s = Student.objects.filter(college = c).get(id = kwargs['sid'])
        serializer = StudentDetailsSerializer(s, data=request.data, context={'cpk': kwargs['id'],'sid':kwargs['sid']})
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


    def delete(self,request,*args,**kwargs):
        college=College.objects.get(id=kwargs['id'])
        student=Student.objects.get(id=kwargs['sid'])
        student.delete()
        return Response()

class CustomAuthToken(ObtainAuthToken):
    def post(self, request, *args, **kwargs):
        serializer = self.serializer_class(data=request.data,
                                           context={'request': request})
        serializer.is_valid(raise_exception=True)
        user = serializer.validated_data['user']
        token, created = Token.objects.get_or_create(user=user)
        return Response({
            'token': token.key,
            'user_id':user.pk

        })

