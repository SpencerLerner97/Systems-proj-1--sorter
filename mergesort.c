#include "Sorter.h"
#include <string.h>
#include <pthread.h>

//global int Tcount=0;

int
count(Record ** head)
{//count how many things are in the list
	int c=0;
	while(*head){
		if(c < 100){
			//printf("%s\n",(**head).genres);
		}
		head = &(**head).next;
		++c;
	}
	//printf("%d\n",c);
	return c;	
}

Record *
split(Record ** head, int count)
{// Count should be the number of elemnts in the list returns a pointer to first node of second half.
	if( count % 2 == 0){
	--count;
	}
	if(count == 3){
	Record ** temp = &((*head)->next);
	Record * secondhead = (*temp)->next;
	(*temp)->next = NULL;
	return secondhead;
	}
	int iter; Record ** temp = head;
	for(iter = count/2; iter > 0; iter --){
	temp = &((*temp)->next);
	}
	Record * secondhead = (*temp)->next;
	(**temp).next = NULL;
	return secondhead;
	
}





Record **
merge(Record ** head, Record ** secondHead, int sortBycol)
{//merge the two lists. Based on sort By col. Sort by col is a zer indexed integer that gives me which column in the struct we are sorting by.
	//printf("%s\n",(**head).genres);
      //printf("H1, %s\nH2 %s\n",(**head).movie_title,(**secondHead).movie_title);
      //printf("%d and %d\n",count(head),count(secondHead));
      if(!(*head)){
      //puts("here1");
          return secondHead;
        }
      if(!(*secondHead)){
        //puts("here2");
        return head;
      }
      int s1 = 0; //if both head,single sized we will set this to 1.
      if(!((*head)->next)){
      s1 = 1;
      }int s2 = 0;
      if(!((*secondHead)->next)){
      s2 = 1;
      }
      
	  switch(sortBycol)
  {
		case 0: //char* color;
      if(strcmp(((*head)->color),((*secondHead)-> color))<=0){
           if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
            if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 1: //char* director_name;
      if(strcmp(((*head)->director_name),((*secondHead)-> director_name))<=0){
               if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
            if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 2: //int num_critic_for_reviews;
      if(((*head)->num_critic_for_reviews) <= (((*secondHead)-> num_critic_for_reviews))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
      if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 3: //int duration;
       if(((*head)->duration) <= (((*secondHead)-> duration))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 4: //int director_facebook_likes;
       if(((*head)->director_facebook_likes) <= (((*secondHead)->director_facebook_likes))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 5: //int actor_3_facebook_likes;
       if(((*head)->actor_3_facebook_likes) <= (((*secondHead)-> actor_3_facebook_likes))){
            if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 6: //char * actor_2_name;
      if(strcmp(((*head)->actor_2_name),((*secondHead)-> actor_2_name))<=0){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 7: //int actor_1_facebook_likes;
       if(((*head)->actor_1_facebook_likes) <= ((*secondHead)-> actor_1_facebook_likes)){
            if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 8: //int gross;
       if(((*head)->gross) <= (((*secondHead)-> gross))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 9: //char * genres;
      if(strcmp(((*head)->genres),((*secondHead)-> genres))<0){
                if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 10: //char * actor_1_name;
      if(strcmp(((*head)->actor_1_name),((*secondHead)-> actor_1_name))<=0){
                if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 11: //char * movie_title;
  	//puts("heree");
      if(strcmp(((*head)->movie_title),((*secondHead)-> movie_title))<=0){
            if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 12: //int num_voted_users;
       if(((*head)->num_voted_users) <= (((*secondHead)-> num_voted_users))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 13: //int cast_total_facebook_likes;
       if(((*head)->cast_total_facebook_likes) <= (((*secondHead)->cast_total_facebook_likes))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 14: //char * actor_3_name;
      if(strcmp(((*head)->actor_3_name),((*secondHead)-> actor_3_name))<=0){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 15: //int facenumber_in_poster;
       if(((*head)->facenumber_in_poster) <= (((*secondHead)-> facenumber_in_poster))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 16: //char * plot_keywords;
      if(strcmp(((*head)->plot_keywords),((*secondHead)->plot_keywords))<=0){
               if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 17: //char * movie_imdb_link;
       if(strcmp(((*head)->movie_imdb_link),((*secondHead)->movie_imdb_link))<=0){
               if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 18: //int num_user_for_reviews;
        if(((*head)->num_user_for_reviews) <= (((*secondHead)-> num_user_for_reviews))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 19: //char * language;
       if(strcmp(((*head)->language),((*secondHead)->language))<=0){
                if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 20: //char * country;
       if(strcmp(((*head)->country),((*secondHead)->country))<=0){
               if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
  	case 21: //char * content_rating;
       if(strcmp(((*head)->content_rating),((*head)->next)->content_rating)<=0){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 22: //int budget;
       if(((*head)->budget) <= (((*secondHead)-> budget))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
        if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 23: //int title_year;
       if(((*head)->title_year) <= (((*secondHead)->title_year))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 24: //int actor_2_facebook_likes;
       if(((*head)->actor_2_facebook_likes) <= (((*secondHead)-> actor_2_facebook_likes))){
              if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
         if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 25: //float imdb_score;
       if(((*head)->imdb_score) <= (((*secondHead)-> imdb_score))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 26: //float aspect_ratio;
       if(((*head)->aspect_ratio) <= (((*secondHead)-> aspect_ratio))){
             if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
          if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
  	case 27: //int movie_facebook_likes;
       if(((*head)->movie_facebook_likes) <= (((*secondHead)-> movie_facebook_likes))){
            if(s1 == 0){
            (*head)->next = *merge(&(*head)->next,secondHead,sortBycol);
            return head;
            }
            (*head)->next = *secondHead;
            return head;
        }
		if(s2 == 0){
          (*secondHead)->next = *merge(head,&((*secondHead)->next),sortBycol);
          return secondHead;
          }
          (*secondHead)->next = *head;
          return secondHead;
		default:
			return head;
  }
}

void* 
threadSort(void * in){//mergesort called by a single void * pointer, a helper function
	mergeMeta *inp = (mergeMeta*)in;
	Record ** sortedHead = malloc(sizeof(Record*));
	*sortedHead = *mergesort(inp->head,inp->sortByCol);
	return (void*) sortedHead;
	}
	
void*
smallThreadSort(void * in){//size is less than two
	//printf("ima\n");
	mergeMeta * inp = (mergeMeta*) in;
	Record ** head = inp->head;
	if((*head) -> next == NULL){//only 1 element
		return (void*) in;
	}
	Record * temp;
	switch(inp->sortByCol){
		case 0: //char* color;
        if(strcmp((*head)->color,((*head)->next)-> color)<=0){
         return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 1: //char* director_name;
        if(strcmp((*head)->director_name,((*head)->next)-> director_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 2: //int num_critic_for_reviews;
  		  if(((*head)->num_critic_for_reviews) <= (((*head)->next)-> num_critic_for_reviews)){
  			           return head;
  		  }
  		  temp = (*head)->next;
  		  temp->next = *head;
  		  (*head)->next = NULL;
  		  *head = temp;
  		  return head;
  		case 3: //int duration;
        if(((*head)->duration) <= (((*head)->next)-> duration)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 4: //int director_facebook_likes;
        if(((*head)->director_facebook_likes) <= (((*head)->next)->director_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 5: //int actor_3_facebook_likes;
        if(((*head)->actor_3_facebook_likes) <= (((*head)->next)-> actor_3_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 6: //char * actor_2_name;
        if(strcmp((*head)->actor_2_name,((*head)->next)-> actor_2_name)<=0){
         return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 7: //int actor_1_facebook_likes;
        if(((*head)->actor_1_facebook_likes) <= (((*head)->next)->actor_1_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 8: //int gross;
        if(((*head)->gross) <= (((*head)->next)-> gross)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 9: //char * genres;
        if(strcmp((*head)->genres,((*head)->next)->genres)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 10: //char * actor_1_name;
        if(strcmp(((*head)->actor_1_name),((*head)->next)-> actor_1_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 11: //char * movie_title;
        if(strcmp((*head)->movie_title,((*head)->next)->movie_title)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 12: //int num_voted_users;
        if(((*head)->num_voted_users) <= (((*head)->next)-> num_voted_users)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 13: //int cast_total_facebook_likes;
        if(((*head)->cast_total_facebook_likes) <= (((*head)->next)-> cast_total_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 14: //char * actor_3_name;
        if(strcmp((*head)->actor_3_name,((*head)->next)-> actor_3_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 15: //int facenumber_in_poster;
        if(((*head)->facenumber_in_poster) <= (((*head)->next)-> facenumber_in_poster)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 16: //char * plot_keywords;
        if(strcmp((*head)->plot_keywords,((*head)->next)-> plot_keywords)<=0){
          return head;
          }
          temp = (*head)->next;
          temp->next = *head;
          (*head)->next = NULL;
          *head = temp;
          return head;
  		case 17: //char * movie_imdb_link;
        if(strcmp((*head)->movie_imdb_link,((*head)->next)-> movie_imdb_link)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 18: //int num_user_for_reviews;
        if(((*head)->num_user_for_reviews) <= (((*head)->next)-> num_user_for_reviews)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 19: //char * language;
        if(strcmp((*head)->language,((*head)->next)-> language)<=0){
          return head;
          }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 20: //char * country;
        if(strcmp((*head)->country,((*head)->next)-> country)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 21: //char * content_rating;
        if(strcmp((*head)->content_rating,((*head)->next)-> content_rating)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 22: //int budget;
        if(((*head)->budget) <= (((*head)->next)-> budget)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 23: //int title_year;
        if(((*head)->title_year) <= (((*head)->next)-> title_year)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 24: //int actor_2_facebook_likes;
        if(((*head)->actor_2_facebook_likes) <= (((*head)->next)-> actor_2_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 25: //float imdb_score;
        if(((*head)->imdb_score) <= (((*head)->next)-> imdb_score)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 26: //float aspect_ratio;
        if(((*head)->aspect_ratio) <= (((*head)->next)-> aspect_ratio)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 27: //int movie_facebook_likes;
        if(((*head)->movie_facebook_likes) <= (((*head)->next)-> movie_facebook_likes)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
	}
		return head;


}
	
	
	/*if(size > 2){//the general case of a list with more than 2 items
		Record * secondHead; Record * fhead;
		secondHead = split(head,size);
		mergeMeta secondHalf, firstHalf;
		secondHalf->head = &secondHead;
		secondHalf->sortByCol = sortByCol;
		fhead = *mergesort(head,sortByCol);
		firstHalf->head = &fhead;
		*head = fhead;
		pthread_t t1,t2;
		int status1,status2;
		status1 = pthread_create(&t1,NULL,threadSort,&secondHalf);
		status2 = pthread_create(&t2,NULL,threadSort,&firstHalf);
		pthread_join(t,(void**) &secondHalf);
		pthread_join(t,(void**) &firstHalf);
		return merge(firstHalf->head,secondHalf->head;,sortByCol);

	*/

	/*	Record * secondHead; Record * fhead;
		secondHead = split(head,size);
		Record ** secondHalf = &secondHead;
		secondHead = *mergesort(secondHalf,sortByCol); //create a new thread here
		fhead = *mergesort(head,sortByCol);
		*head = fhead;
		*secondHalf  = secondHead;
		return merge(head,secondHalf,sortByCol);
		*/
		
	
	
Record **
mergesort(Record ** head, int sortByCol)
 {//mergesort on head done by which column. COlumn is currently a string but we may swithc it to a int.
	 int size = count(head);
	 if(size > 2000){//the general case of a list with more than 2 items
	 		Record *secondHead = malloc(sizeof(Record)); Record *fhead = malloc(sizeof(Record));
	 		Record  **secondHEAD=malloc(sizeof(Record*)); Record **firstHEAD=malloc(sizeof(Record*));
			secondHead = split(head,size);
			mergeMeta secondHalf, firstHalf;
			secondHalf.head = &secondHead;
			secondHalf.sortByCol = sortByCol;
			firstHalf.head = head;
			firstHalf.sortByCol = sortByCol;
			pthread_t t1,t2;
			int status1,status2;
			status1 = pthread_create(&t1,NULL,threadSort,&secondHalf);
			status2 = pthread_create(&t2,NULL,threadSort,&firstHalf);
			pthread_join(t1,(void**) &secondHEAD);
			pthread_join(t2,(void**) &firstHEAD);
			return merge(secondHEAD,firstHEAD,sortByCol);
	}
	if(size > 2){
	Record * secondHead; Record * fhead;
		secondHead = split(head,size);
		Record ** secondHalf = &secondHead;
		secondHead = *mergesort(secondHalf,sortByCol); //create a new thread here
		fhead = *mergesort(head,sortByCol);
		*head = fhead;
		*secondHalf  = secondHead;
		return merge(head,secondHalf,sortByCol);
		}
	if((*head) -> next == NULL){//only 1 element
		return head;
	}
	Record * temp;
	switch(sortByCol){
		case 0: //char* color;
        if(strcmp((*head)->color,((*head)->next)-> color)<=0){
         return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 1: //char* director_name;
        if(strcmp((*head)->director_name,((*head)->next)-> director_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 2: //int num_critic_for_reviews;
  		  if(((*head)->num_critic_for_reviews) <= (((*head)->next)-> num_critic_for_reviews)){
  			           return head;
  		  }
  		  temp = (*head)->next;
  		  temp->next = *head;
  		  (*head)->next = NULL;
  		  *head = temp;
  		  return head;
  		case 3: //int duration;
        if(((*head)->duration) <= (((*head)->next)-> duration)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 4: //int director_facebook_likes;
        if(((*head)->director_facebook_likes) <= (((*head)->next)->director_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 5: //int actor_3_facebook_likes;
        if(((*head)->actor_3_facebook_likes) <= (((*head)->next)-> actor_3_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 6: //char * actor_2_name;
        if(strcmp((*head)->actor_2_name,((*head)->next)-> actor_2_name)<=0){
         return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 7: //int actor_1_facebook_likes;
        if(((*head)->actor_1_facebook_likes) <= (((*head)->next)->actor_1_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 8: //int gross;
        if(((*head)->gross) <= (((*head)->next)-> gross)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 9: //char * genres;
        if(strcmp((*head)->genres,((*head)->next)->genres)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 10: //char * actor_1_name;
        if(strcmp(((*head)->actor_1_name),((*head)->next)-> actor_1_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 11: //char * movie_title;
        if(strcmp((*head)->movie_title,((*head)->next)->movie_title)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 12: //int num_voted_users;
        if(((*head)->num_voted_users) <= (((*head)->next)-> num_voted_users)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 13: //int cast_total_facebook_likes;
        if(((*head)->cast_total_facebook_likes) <= (((*head)->next)-> cast_total_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 14: //char * actor_3_name;
        if(strcmp((*head)->actor_3_name,((*head)->next)-> actor_3_name)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 15: //int facenumber_in_poster;
        if(((*head)->facenumber_in_poster) <= (((*head)->next)-> facenumber_in_poster)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 16: //char * plot_keywords;
        if(strcmp((*head)->plot_keywords,((*head)->next)-> plot_keywords)<=0){
          return head;
          }
          temp = (*head)->next;
          temp->next = *head;
          (*head)->next = NULL;
          *head = temp;
          return head;
  		case 17: //char * movie_imdb_link;
        if(strcmp((*head)->movie_imdb_link,((*head)->next)-> movie_imdb_link)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 18: //int num_user_for_reviews;
        if(((*head)->num_user_for_reviews) <= (((*head)->next)-> num_user_for_reviews)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 19: //char * language;
        if(strcmp((*head)->language,((*head)->next)-> language)<=0){
          return head;
          }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 20: //char * country;
        if(strcmp((*head)->country,((*head)->next)-> country)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 21: //char * content_rating;
        if(strcmp((*head)->content_rating,((*head)->next)-> content_rating)<=0){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 22: //int budget;
        if(((*head)->budget) <= (((*head)->next)-> budget)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 23: //int title_year;
        if(((*head)->title_year) <= (((*head)->next)-> title_year)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 24: //int actor_2_facebook_likes;
        if(((*head)->actor_2_facebook_likes) <= (((*head)->next)-> actor_2_facebook_likes)){
        return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 25: //float imdb_score;
        if(((*head)->imdb_score) <= (((*head)->next)-> imdb_score)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 26: //float aspect_ratio;
        if(((*head)->aspect_ratio) <= (((*head)->next)-> aspect_ratio)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
  		case 27: //int movie_facebook_likes;
        if(((*head)->movie_facebook_likes) <= (((*head)->next)-> movie_facebook_likes)){
          return head;
        }
        temp = (*head)->next;
        temp->next = *head;
        (*head)->next = NULL;
        *head = temp;
        return head;
	}
		return head;


}
	
	
	
	/*else{
	Record **fhead;
	mergeMeta* Singleton=malloc(sizeof(mergeMeta));//only need one of these
	Singleton->head = head;
	Singleton->sortByCol = sortByCol;
	return (Record**) smallThreadSort(Singleton);
	}
}*/
	/*if(size > 2){
		//puts("lol");
		Record * secondHead; Record * fhead;
		secondHead = split(head,size);
		Record ** secondHalf = &secondHead;
		secondHead = *mergesort(secondHalf,sortByCol); //create a new thread here
		fhead = *mergesort(head,sortByCol);
		*head = fhead;
		*secondHalf  = secondHead;
		return merge(head,secondHalf,sortByCol);
	}*/
